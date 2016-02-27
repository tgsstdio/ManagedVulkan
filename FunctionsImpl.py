import xml.etree.ElementTree as ET
tree = ET.parse('vk.xml')
root = tree.getroot()

class VkFunction:
    def __init__(self, name):
        self.name = name
        self.success = None
        self.failed = None
        self.params = []

    def addParams(self, param):
        self.params.append(param)

    def display(self):
        print(self.name, self.returnType, self.success, self.failed)    
        for param in self.params:
            print('   ', param.tokens)

class VkFunctionParam:
    def __init__(self, name):
        self.text = ''
        self.tokens = []        
        self.type = ''
        self.name = name

class VkClassMethod:
    def __init__(self, fn):
        self.name = fn.name[2:]
        self.params = fn.params[1:]
        self.fn = fn

class VkClassObject:
    def __init__(self, key):
        self.key = key
        self.name = key[2:]
        self.methods = []

    def addFn(self, fn):
        self.methods.append(VkClassMethod(fn))

functions = []

commands = root.findall('commands/command')
for child in commands:
    name = child.find('proto/name').text    
    f = VkFunction(name)
    f.returnType = child.find('proto/type').text
    
    success = child.attrib.get('successcodes')

    if not success is None:
        f.success = success.split(',')

    failed = child.attrib.get('errorcodes')

    if not failed is None:
        f.failed = failed.split(',')
        
    for param in child.findall('param'):
        p = VkFunctionParam()
        p.text = "".join(param.itertext())
        p.tokens = p.text.split()        
        p.type = param.find('type').text
        p.name = param.find('name').text
        f.addParams(p)
        
    functions.append(f)    
#    print (child.text)

print ("Functions", len(functions) )

#for i in range(0,10):
    #functions[i].display() 

enumFn = lambda a: a.name.startswith('vkEnum')
notFn = lambda a: not enumFn(a)

# remaining = list(filter(notFn, functions))
# print(len(remaining))

loops = list(filter(enumFn, functions))
# print('ENUMERATE FUNCTIONS', len(loops))

#for l in loops:
#    l.display()

# INSTANCE FUNCTIONS
instFn = lambda a: len(a.params[0].tokens) == 2 and not a.params[0].tokens[0].endswith('*')
instances = list(filter(instFn, functions))
print('INSTANCE FUNCTIONS', len(instances))

chunks = {}
for i in instances:
    moduleName = i.params[0].tokens[0]
    if not moduleName in chunks:
        chunks[moduleName] = VkClassObject(moduleName)    
    chunks[moduleName].addFn(i)    

for key in chunks.keys():
    item = chunks[key]
    print(item.key, item.name, len(item.methods))

    

