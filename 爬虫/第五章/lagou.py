from selenium .webdriver import Chrome
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time


web=Chrome()

web.get("http://lagou.com")
web.find_element(By.XPATH,'//*[@id="changeCityBox"]/ul/li[1]/a').click()
print("please waiting")
time.sleep(2)
web.find_element(By.XPATH,'//*[@id="search_input"]').send_keys("python",Keys.ENTER)
div_list=web.find_elements(By.XPATH,'//*[@id="jobList"]/div[1]/div')
print(div_list)
for div in div_list:
    job_name=div.find_element(By.XPATH,'//*[@id="jobList"]/div[1]/div[1]/div[1]/div[1]/div[1]/a').text
    money=div.find_element(By.XPATH,'//*[@id="jobList"]/div[1]/div[1]/div[1]/div[1]/div[2]/span').text
    print(job_name,money)
