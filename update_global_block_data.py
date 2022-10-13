from threading import local
import pandas as pd
'''
In this file, the global net transaction values of all the blocks will be updated
'''
global_df = pd.read_csv('global_block_data.csv')
local_df = pd.read_csv('local_data/one_game_net_trans.csv')
global_df['Net Transaction Value'] += local_df['Net Transaction Value']
global_df.to_csv('global_block_data.csv',index_label=False,index=False)
