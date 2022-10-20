'''
This file resets all the global data available.
'''

parent_folder = 'C:/Users/Ravi G/Desktop/Aditya/BusinessSimulation'
import pandas as pd
from reset_global_colour_house_wise_data import *
from reset_global_IR_ratio import *
from reset_global_white_level_wise_data import *
from reset_global_block_data import *

'''
First reset global block data
'''

reset_block_data()


'''
Reset global IR ratio
'''

reset_global_IR()


'''
Reset global_colour_house_wise_data.csv
'''


reset_global_colour_house_wise_data()


'''
reset global_white_level_wise_data
'''


reset_white_level_wise_data()


'''
Now reset the number of times the game has been simulated to 0
'''

with open(parent_folder+'/visits.txt',"w") as visits_file:
    visits_file.write('0')
    visits_file.close()
    