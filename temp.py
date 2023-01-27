import pandas as  pd
import os
parent_folder = os.getcwd()
global_inv_df = pd.read_csv(parent_folder+'/global_data/global_total_investment.csv')
global_ret_df = pd.read_csv(parent_folder+'/global_data/global_total_return.csv')
global_df = pd.read_csv(parent_folder+'/global_data/global_IR_ratio.csv')
global_df['IR ratio value'] = (global_ret_df["Total Return"] - global_inv_df["Total Investment"])/global_inv_df["Total Investment"]
global_df.to_csv(parent_folder+'/global_data/global_IR_ratio.csv',index=False,index_label=False)
