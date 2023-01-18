#cwd
import os
cwd = os.getcwd()

#first, import the csv module
import pandas as pd

#next, import the matplotlib module
import matplotlib.pyplot as plt

#importing numpy
import seaborn as sns

#now, create a file object and read all the data into a buffer with each row as a dict
house_wise_df = pd.read_csv(cwd +'/global_data/global_colour_house_wise_return.csv')
house_wise_ret = [sum(house_wise_df[' 0 Houses']),sum(house_wise_df[' 1 House']),sum(house_wise_df[' 2 Houses']),sum(house_wise_df[' 3 Houses']),sum(house_wise_df[' Hotel'])]

#plotting the line graph
plt.pie(house_wise_ret,labels= ['0 houses','1 House','2 Houses','3 Houses','Hotel'],autopct="%1.1f%%")
plt.title('House Wise return')
plt.show()