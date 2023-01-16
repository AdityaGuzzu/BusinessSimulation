import pandas as pd
def reset_house_wise_IR():
    parent_folder = parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
    colour_house_wise_inv_df = pd.read_csv(parent_folder + '/global_data/global_colour_house_wise_investment.csv')
    colour_house_wise_ret_df = pd.read_csv(parent_folder + '/global_data/global_colour_house_wise_return.csv')
    colour_house_wise_IR_df = pd.read_csv(parent_folder+'/global_data/global_colour_house_wise_IR.csv')
    colour_house_wise_inv_df[[' 0 Houses', ' 1 House',' 2 Houses',' 3 Houses',' Hotel']] = 0
    colour_house_wise_ret_df[[' 0 Houses', ' 1 House',' 2 Houses',' 3 Houses',' Hotel']] = 0
    colour_house_wise_IR_df[[' 0 Houses', ' 1 House',' 2 Houses',' 3 Houses',' Hotel']] = 0
    colour_house_wise_inv_df.to_csv(parent_folder + '/global_data/global_colour_house_wise_investment.csv',index=False,index_label=False)
    colour_house_wise_ret_df.to_csv(parent_folder + '/global_data/global_colour_house_wise_return.csv',index=False,index_label=False)
    colour_house_wise_IR_df.to_csv(parent_folder+'/global_data/global_house_wise_IR.csv',index=False,index_label=False)