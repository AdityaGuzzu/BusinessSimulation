'''
This file contains the definition if a function to reset the 
level wise white ticket data  globally.
'''
import pandas as pd
parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
def reset_white_level_wise_data():  
    df = pd.read_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv')
    df[['No Double Rent','Double Rent']] = 0
    df.to_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv',index=False,index_label=False)
