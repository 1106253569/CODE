from lxml import etree
from selenium.webdriver import Chrome
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

url = "http://www.glidedsky.com/login"

web = Chrome()

web.get(url)
web.find_element(By.XPATH, '//*[@id="email"]').send_keys('1106253569@qq.com')
web.find_element(By.XPATH, '//*[@id="password"]').send_keys('asdf8296776')
web.find_element(
    By.XPATH,
    '//*[@id="app"]/main/div[1]/div/div/div/div[2]/form/div[4]/div/button'
).click()
time.sleep(2)

web.find_element(
    By.XPATH,
    '//*[@id="app"]/main/div[1]/div/div/table/tbody/tr/td[1]/a').click()
web.find_element(By.XPATH,
                 '//*[@id="app"]/main/div[1]/div/div/div/div/a').click()
web.switch_to.window(web.window_handles[-1])
page = web.page_source
print(page)

tree = etree.HTML(page)
html = tree.xpath("//div[@class='col-md-1']/text()")
sum_int = 0
for item in html:
    sum_int += int(item.strip())
    print(sum_int)
