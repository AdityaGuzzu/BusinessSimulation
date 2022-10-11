'''
In this file, we will plot a simple bar diagram of the output recieved from the game simulation
'''

#first, import the csv module
import pandas as pd

#next, import the matplotlib module
import matplotlib.pyplot as plt

#importing numpy
import seaborn as sns

#now, create a file object and read all the data into a buffer with each row as a dict
game_data_df = pd.read_csv(r'C:\Users\Ravi G\Desktop\Aditya\BusinessSimulation\data\one_game_net_trans.csv')


#plotting the line graph
sns.set_style("darkgrid")
plt.xticks(rotation=90)
plt.bar(game_data_df['Block Name'], game_data_df['Net Transaction Value'], color="aqua")
plt.title('Single Game Data visualisation')
plt.show()


