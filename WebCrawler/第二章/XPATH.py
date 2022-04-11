from lxml import etree

#error：lxml.etree.XMLSyntaxError: Opening and ending tag mismatch
#访问HTML文件时，路径存在中文，导致读取错误
#解决方法：创建HTML解释器，增加parser，指定编码格式
parser = etree.HTMLParser(encoding='UTF-8')
tree = etree.parse('demo.html',parser=parser)

#result = tree.xpath("/html/body/ul/li/a/text()")
#print(result)

ol_li_list = tree.xpath("/html/body/ol/li")

for li in ol_li_list:
    #从每一个li中提取到文字信息
    result = li.xpath("./a/text()") #获取文本
    print(result)
    result2 = li.xpath("./a/@href") #获取属性值: @属性
    print(result2)

print(tree.xpath("/html/body/ul/li/a/@href"))