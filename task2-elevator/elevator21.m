function elevator21( floors,direction,destination )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

  
       if( direction==0)
    for n =floors:-1:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(direction==1)
    for n = floors:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
       end
        guidata(hObject, handles);
end

