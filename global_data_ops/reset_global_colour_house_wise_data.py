'''
A function to reset global colour house wise data
'''
import pandas as pd
def reset_global_colour_house_wise_data():
    parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
    global_df = pd.read_csv(parent_folder+'/global_data/global_colour_house_wise_data.csv')
    global_df[["0 houses","1 house","2 houses","3 houses","hotel"]] = 0
    global_df.to_csv(parent_folder+'/global_data/global_colour_house_wise_data.csv',index=False,index_label=False)