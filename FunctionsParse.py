import xml.etree.ElementTree as ET
tree = ET.parse('vk.xml')
root = tree.getroot()

# print ("Functions")
# commands = root.findall('commands/command/proto/name')
# for child in commands:
#    print (child.text)

# print ("Structs")
# structs = root.findall("types/type/[@category='struct']")
# for child in structs:
#    print (child.attrib['name'])

print ("Enums")
structs = root.findall("types/type/[@category='enum']")
for child in structs:
    print (child.attrib['name'])
