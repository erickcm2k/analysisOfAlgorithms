
x = [100, 1000, 5000, 10000, 50000, 200000, 400000, 600000, 800000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000]

tiempo_real = [0.0006430149,0.0011920929,0.0038630962,0.0077760220,0.0449399948,0.2023949623,0.4814920425,0.7925539017,1.1468989849,1.5021829605,3.4618101120,5.5703141689,7.7122220993,10.0891699791,12.3830151558,14.7475128174,17.1137609482,19.5558428764,22.5793399811]
estimaciones = [15000000,20000000,500000000,1000000000,5000000000]
n = 8
p=polyfit(x,tiempo_real,n)
xi=linspace(15000000,5000000000);
z=polyval(p,estimaciones)



t_real = plot(estimaciones, z)
t_real.Marker = 'o'
t_real.Color = 'b'
title('Aproximaciones')
ylabel('Tiempo (s)');
xlabel('Tamaño de entrada');

