x = [1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000]
tiempo_real = [8.2612037659,8.24213027953,7.9011917114,8.9192390442,7.2097778320,7.2312355042,7.4791908264,7.6007843018,7.9488754272,9.1314315796]



t_real = plot(x, tiempo_real)
t_real.Marker = 'o'
legend([t_real],'Tiempo Real')

title('Árbol Binario de Búsqueda')
ylabel('Tiempo (s)');
xlabel('Tamaño de entrada');
