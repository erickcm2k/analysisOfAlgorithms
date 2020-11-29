x = [1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000]
tiempo_real = [8.2612037659,8.24213027953,7.9011917114,8.9192390442,7.2097778320,7.2312355042,7.4791908264,7.6007843018,7.9488754272,9.1314315796]

n = 8
p=polyfit(x,tiempo_real,n)
xi=linspace(1000000,10000000);
z=polyval(p,xi)

hold on

poly = plot(xi, z)
poly.Color = 'r'
poly.Marker = 'o'

title('Polinomio para ABB')
t_real = plot(x, tiempo_real)
t_real.Marker = 'o'
t_real.Color = 'b'

hold off