import pandas as pd
df = pd.read_csv(r'../local_data/colour_house_wise_data.csv')
df[['0 houses','1 house','2 houses','3 houses','hotel']] = 0
df.to_csv(r'../global_data/global_colour_house_wise_data.csv',index=False)

df = pd.read_csv(r'../local_data/white_level_wise_trans.csv')
df[['No Double Rent','Double Rent']] = 0
df.to_csv(r'../global_data/global_white_level_wise_trans.csv',index=False)