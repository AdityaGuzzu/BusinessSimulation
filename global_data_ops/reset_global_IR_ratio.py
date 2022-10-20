'''
Reset global IR ratio
'''
import pandas as pd
def reset_global_IR():
    parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
    df = pd.read_csv(parent_folder+'global_data/global_IR_ratio.csv') 
    df['IR ratio value'] = 0.0
    df.to_csv(parent_folder+'/global_data/global_IR_ratio.csv',index=False,index_label=False)

