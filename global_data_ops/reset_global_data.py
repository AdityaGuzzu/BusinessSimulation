import pandas as pd
df = pd.read_csv('../global_data/global_block_data.csv')
df['Net Transaction Value'] = 0
df.to_csv('../global_data/global_block_data.csv',index=False,index_label=False)