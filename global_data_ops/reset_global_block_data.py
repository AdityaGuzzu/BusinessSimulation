'''
This file contains the definition if a function to reset the block data globally.
'''

import pandas as pd
parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'

def reset_block_data():
    df = pd.read_csv(parent_folder+'/global_data/global_block_data.csv')
    df['Net Transaction Value'] = 0
    df.to_csv(parent_folder+'/global_data/global_block_data.csv',index=False,index_label=False)