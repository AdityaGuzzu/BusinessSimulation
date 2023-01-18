'''
A program to plot the pie chart of total investment on each ticket
'''
import os
import pandas as pd
import matplotlib.pyplot as plt
cwd = os.getcwd()
investment_df = pd.read_csv(cwd+'/global_data/global_total_investment.csv')
plt.pie(investment_df['Total Investment'],labels=investment_df['Block Name'],autopct='%1.1f%%',rotatelabels=True)
plt.show()