x = [100, 1000, 5000, 10000, 50000, 200000, 400000, 600000, 800000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000]

tiempo_real = [0.0006430149,0.0011920929,0.0038630962,0.0077760220,0.0449399948,0.2023949623,0.4814920425,0.7925539017,1.1468989849,1.5021829605,3.4618101120,5.5703141689,7.7122220993,10.0891699791,12.3830151558,14.7475128174,17.1137609482,19.5558428764,22.5793399811]

xi=linspace(100,10000000);

% Grado 1
n1 = 1
p1=polyfit(x,tiempo_real,n1)
z1=polyval(p1,xi)
% Grado 2
n2 = 2
p2=polyfit(x,tiempo_real,n2)
z2=polyval(p2,xi)
% Grado 3
n3 = 3
p3=polyfit(x,tiempo_real,n3)
z3=polyval(p3,xi)
% Grado 4
n4 = 4
p4=polyfit(x,tiempo_real,n4)
z4=polyval(p4,xi)
% Grado 8
n5 = 8
p5=polyfit(x,tiempo_real,n5)
z5=polyval(p5,xi)


%
%
% Gráficas
%
%

hold on
        
t_real = plot(x, tiempo_real)
t_real.Color = 'r'

% Grado 1

poly1 = plot(xi, z1)
poly1.Color = 	[0, 0.4470, 0.7410]
poly1.Marker = 'o'

% Grado 2

poly2 = plot(xi, z2)
poly2.Color = [0.8500, 0.3250, 0.0980]
poly2.Marker = 'o'

% Grado 3

poly3 = plot(xi, z3)
poly3.Color = [0.9290, 0.6940, 0.1250]
poly3.Marker = 'o'

% Grado 4

poly4 = plot(xi, z4)
poly4.Color = [0.4940, 0.1840, 0.5560]
poly4.Marker = 'o'


% Grado 8

poly5 = plot(xi, z5)
poly5.Color = [0.4660, 0.6740, 0.1880]
poly5.Marker = 'o'

hold off

legend([t_real, poly1,poly2,poly3,poly4,poly5],'Tiempo Real','Grado 1','Grado 2','Grado 3','Grado 4','Grado 8')