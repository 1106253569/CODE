from lxml import etree
from selenium.webdriver import Chrome
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import random

url = "https://login.kwaixiaodian.com/?biz=&redirect_url=https%3A%2F%2Fzs.kwaixiaodian.com%2Fpage%2Fhelper"

web = Chrome()

web.get(url)

time.sleep(60)
while True:
    web.find_element(
        By.XPATH,
        '//*[@id="main-container"]/section/main/div/div[2]/div[2]/div[2]/div/div[2]/div/input'
    ).send_keys('好穿又透气', Keys.ENTER)
    time.sleep(10+random.random())
    web.find_element(
        By.XPATH,
        '//*[@id="main-container"]/section/main/div/div[2]/div[2]/div[2]/div/div[2]/div/input'
    ).send_keys('放心购买,支持7天无理由退货', Keys.ENTER)
    time.sleep(30+random.random())

