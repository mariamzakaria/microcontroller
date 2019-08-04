s=serial('COM6','BAUD', 9600); % Make sure the baud rate and COM port is 
                              % same as in Arduino IDE
fopen(s);

for m=1:10                    % The program will execute 10 times , 
                              %you can change the vaalue of m to increase or decrease
                              %the number of executions

%servalue= input('Enter the value 100 to turn ON LED & 101 to turn OFF LED :');

fprintf(s,10);
 elevator=fread(s,1)-48
 
fprintf(s,20);
 floors=fread(s,1)-48
fprintf(s,30);
direction=fread(s,1)-48
fprintf(s,40);
fprintf(s,1);
newfloor=fread(s,1)-48%This command will send entered value to Arduino 
end
