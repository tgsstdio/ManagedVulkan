import xml.etree.ElementTree as ET
tree = ET.parse('vk.xml')
root = tree.getroot()

class VkFunction:
    def __init__(self):
        self.params = []

    def addParams(self, param):
        self.params.append(param)

class VkFunctionParam:
    def __init__(self):
        pass    

functions = []

commands = root.findall('commands/command')
for child in commands:
    f = VkFunction()
    f.name = child.find('proto/name').text
    f.returnType = child.find('proto/type').text
    
    success = child.attrib.get('successcodes')

    if success is None:
        f.success = None
    else:
        f.success = success.split(',')

    failed = child.attrib.get('errorcodes')

    if failed is None:
        f.failed = None
    else:
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

for i in range(0,10):
    f = functions[i]    
    print(f.name, f.returnType, f.success, f.failed)    
    for param in f.params:
        print('   ', param.tokens)
