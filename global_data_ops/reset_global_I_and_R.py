import pandas as pd
def reset_global_I_and_R():
    parent_folder = parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
    global_inv_df = pd.read_csv(parent_folder+'/global_data/global_total_investment.csv')
    global_inv_df['Total Investment'] = 0
    global_inv_df.to_csv(parent_folder+'/global_data/global_total_investment.csv',index=False,index_label=False)
    global_ret_df = pd.read_csv(parent_folder+'/global_data/global_total_return.csv')
    global_ret_df['Total Return'] = 0
    global_ret_df.to_csv(parent_folder+'/global_data/global_total_return.csv',index=False,index_label=False)