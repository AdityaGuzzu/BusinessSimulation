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
ROI_df = pd.read_csv(cwd +'/global_data/global_IR_ratio.csv')


#plotting the line graph
sns.set_style("darkgrid")
plt.xticks(rotation=90)
plt.bar(ROI_df['Block Name'], ROI_df['IR ratio value'], color="aqua")
plt.title('ROI')
plt.show()