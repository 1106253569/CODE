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
web.find_element(By.XPATH,'//*[@id="jobList"]/div[1]/div[1]/div[1]/div[1]/div[1]/a').click()
web.switch_to.window(web.window_handles[-1])
job_detail=web.find_element(By.XPATH,'//*[@id="job_detail"]/dd[2]/div').text
print(job_detail)

web.close()
#web.switch_to.default_content()
web.switch_to.window(web.window_handles[0])
web.find_element(By.XPATH,'//*[@id="jobList"]/div[1]/div[1]/div[1]/div[1]/div[1]/a').click()
web.switch_to.window(web.window_handles[-1])
job_detail=web.find_element(By.XPATH,'//*[@id="job_detail"]/dd[2]/div').text
print(job_detail)