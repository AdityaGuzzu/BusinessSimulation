
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
update the global data of white tickets
'''

local_df = pd.read_csv(parent_folder+'/local_data/white_level_wise_trans.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv')
global_df[["No Double Rent","Double Rent"]] += local_df[["No Double Rent","Double Rent"]]
global_df.to_csv(parent_folder+'/global_data/global_white_level_wise_trans.csv',index=False,index_label=False)

'''
Update Global House wise investment and returns
'''
local_inv_df = pd.read_csv(parent_folder+'/local_data/house_wise_investment.csv')
local_ret_df = pd.read_csv(parent_folder + '/local_data/house_wise_return.csv')
global_inv_df = pd.read_csv(parent_folder+'/global_data/global_colour_house_wise_investment.csv')
global_ret_df = pd.read_csv(parent_folder + '/global_data/global_colour_house_wise_return.csv')

global_inv_df[[" 0 Houses"," 1 House"," 2 Houses"," 3 Houses"," Hotel"]] += local_inv_df[[" 0 Houses"," 1 House"," 2 Houses"," 3 Houses"," Hotel"]]
global_ret_df[[" 0 Houses"," 1 House"," 2 Houses"," 3 Houses"," Hotel"]] += local_ret_df[[" 0 Houses"," 1 House"," 2 Houses"," 3 Houses"," Hotel"]]
global_inv_df.to_csv(parent_folder+'/global_data/global_colour_house_wise_investment.csv',index=False,index_label=False)
global_ret_df.to_csv(parent_folder+'/global_data/global_colour_house_wise_return.csv',index=False, index_label=False)

'''
Updating global investment and return
'''
global_inv_df = pd.read_csv(parent_folder+'/global_data/global_total_investment.csv')
global_ret_df = pd.read_csv(parent_folder+'/global_data/global_total_return.csv')
local_inv_df = pd.read_csv(parent_folder+'/local_data/total_investment.csv')
local_ret_df = pd.read_csv(parent_folder+'/local_data/total_return.csv')
global_inv_df['Total Investment'] += local_inv_df['Total Investment']
global_ret_df['Total Return'] += local_ret_df['Total Return']
global_ret_df.to_csv(parent_folder+'/global_data/global_total_return.csv',index=False,index_label=False)
global_inv_df.to_csv(parent_folder+'/global_data/global_total_investment.csv',index=False,index_label=False)

'''
Updating the global IR ratio 
'''

global_inv_df = pd.read_csv(parent_folder+'/global_data/global_total_investment.csv')
global_ret_df = pd.read_csv(parent_folder+'/global_data/global_total_return.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_IR_ratio.csv')
global_df['IR ratio value'] = (global_ret_df["Total Return"] - global_inv_df["Total Investment"])/global_inv_df["Total Investment"]
global_df.to_csv(parent_folder+'/global_data/global_IR_ratio.csv',index=False,index_label=False)

'''
Updating global house wise IR ratio
'''

global_inv_df = pd.read_csv(parent_folder+'\global_data\global_colour_house_wise_investment.csv')
global_ret_df = pd.read_csv(parent_folder+'\global_data\global_colour_house_wise_return.csv')
global_IR_df = pd.read_csv(parent_folder+'/global_data/global_house_wise_IR.csv')
global_IR_df[' 0 Houses'] = (global_ret_df[' 0 Houses']-global_inv_df[' 0 Houses'])/global_inv_df[' 0 Houses']
global_IR_df[' 1 House'] = (global_ret_df[' 1 House']-global_inv_df[' 1 House'])/global_inv_df[' 1 House']
global_IR_df[' 2 Houses'] = (global_ret_df[' 2 Houses']-global_inv_df[' 2 Houses'])/global_inv_df[' 2 Houses']
global_IR_df[' 3 Houses'] = (global_ret_df[' 3 Houses']-global_inv_df[' 3 Houses'])/global_inv_df[' 3 Houses']
global_IR_df[' Hotel'] = (global_ret_df[' Hotel']-global_inv_df[' Hotel'])/global_inv_df[' Hotel']
global_IR_df.to_csv(parent_folder+'/global_data/global_house_wise_IR.csv',index=False,index_label=False)