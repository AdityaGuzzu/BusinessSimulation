
import pandas as pd

'''
In this file, the global net transaction values of all the blocks will be updated
'''

parent_folder = 'C://Users/Ravi G/Desktop/Aditya/BusinessSimulation'

global_df = pd.read_csv(parent_folder+'/global_data/global_block_data.csv')
local_df = pd.read_csv(parent_folder+'/local_data/one_game_net_trans.csv')
global_df['Net Transaction Value'] += local_df['Net Transaction Value']
global_df.to_csv(parent_folder+'/global_data/global_block_data.csv',index_label=False,index=False)

'''
updating the global data of colour tickets
'''

local_df = pd.read_csv(parent_folder+'/local_data/colour_house_wise_data.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_colour_house_wise_data.csv')
global_df[["0 houses","1 house","2 houses","3 houses","hotel"]] += local_df[["0 houses","1 house","2 houses","3 houses","hotel"]]
global_df.to_csv(parent_folder+'/global_data/global_colour_house_wise_data.csv',index=False,index_label=False)


'''
updating the global data of white tickets
'''


local_df = pd.read_csv(parent_folder+'/local_data/white_level_wise_trans.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv')
global_df[["No Double Rent","Double Rent"]] += local_df[["No Double Rent","Double Rent"]]
global_df.to_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv',index=False,index_label=False)


'''
Updating the global IR ratio 
'''
with open(parent_folder+'/visits.txt') as visits_file:
    num_of_visits = int(visits_file.read())
    visits_file.close()
    
local_df = pd.read_csv(parent_folder+'/local_data/IR_ratio.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_IR_ratio.csv')

global_df['IR ratio value'] += local_df['IR ratio value']
global_df['IR ratio value'] /= num_of_visits
global_df.to_csv(parent_folder+'/global_data/global_IR_ratio.csv',index=False, index_label=False)
