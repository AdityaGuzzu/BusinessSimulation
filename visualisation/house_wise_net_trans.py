'''
In this file, we will plot a simple bar diagram of the output recieved from the game simulation
'''
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
house_wise_df = pd.read_csv(cwd +'/global_data/global_colour_house_wise_data.csv')
house_wise_trans = [sum(house_wise_df['0 houses']),sum(house_wise_df['1 house']),sum(house_wise_df['2 houses']),sum(house_wise_df['3 houses']),sum(house_wise_df['hotel'])]

#plotting the line graph
sns.set_style("darkgrid")
plt.xticks(rotation=90)
plt.bar( ['0 houses','1 House','2 Houses','3 Houses','Hotel'],house_wise_trans, color="aqua")
plt.title('House Wise Net Trans')
plt.show()