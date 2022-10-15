import pandas as pd


'''
First updating the global data of colour tickets
'''


local_df = pd.read_csv(r'../local_data/colour_house_wise_data.csv')
global_df = pd.read_csv(r'../global_data/global_colour_house_wise_data.csv')
global_df[["0 houses","1 house","2 houses","3 houses","hotel"]] += local_df[["0 houses","1 house","2 houses","3 houses","hotel"]]
global_df.to_csv(r'../global_data/global_colour_house_wise_data.csv',index=False,index_label=False)


'''
Now updating the global data of white tickets
'''


local_df = pd.read_csv(r'../local_data/white_level_wise_trans.csv')
global_df = pd.read_csv(r'../global_data/global_white_level_wise_trans.csv')
global_df[["No Double Rent","Double Rent"]] += local_df[["No Double Rent","Double Rent"]]
global_df.to_csv(r'../global_data/global_white_level_wise_trans.csv',index=False,index_label=False)
