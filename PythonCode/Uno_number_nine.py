from BusinessBoard.listchecker import *
tickets = ["Start", "England", "Iraq", "Waterways", "UNO", "France", "Iran", "Satellite", "Egypt", "Resort", "Canada",
           "Germany", "Airways", "Customs duty", "Switzerland", "Brazil", "Chance", "Italy", "Party House", "Japan",
           "USA", "Travelling Duty", "Roadways", "Mexico", "Hong Kong", "UNO", "Australia", "Jail", "India", "Chance",
           "Saudi Arabia", "Petroleum", "China", "Railways", "Malaysia", "Singapore"]
def UNOnumber9(ticket_list_of_the_player, house_list):
    amount_to_be_paid = 0
    for i in ticket_list_of_the_player:
        if 0 < check(house_list, i) <= 3:
            amount_to_be_paid += house_list.check(i)*50
        elif check(house_list, i) == 4:
            amount_to_be_paid += 250
    return amount_to_be_paid