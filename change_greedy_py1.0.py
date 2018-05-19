#Make change

owed = int(input('Enter the amount owed: '))
currency_no = int(input('Enter number of denominations: '))

coins_list = []
good_picks = []

print('Enter the denominations in descending order: ')
for i  in range(currency_no):
	store = input()
	coins_list.append(store)
	
for i in range(currency_no):
	good_picks.append(0)

for i in range(currency_no):
	good_picks[i] = owed / int(coins_list[i])
	owed = owed % int(coins_list[i])

if owed == 0:
	print('Solution:')
	for i in range(currency_no):
		print(int(coins_list[i]), end = ' ')
		print("X", end = ' ')
		print(int(good_picks[i]))