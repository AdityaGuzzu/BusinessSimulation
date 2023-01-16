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
game_data_df = pd.read_csv(cwd +'/global_data/global_block_data.csv')


#plotting the line graph
sns.set_style("darkgrid")
plt.xticks(rotation=90)
plt.bar(game_data_df['Block Name'], game_data_df['Net Transaction Value'], color="aqua")
plt.title('Global Net Transaction value')
plt.show()


