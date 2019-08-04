function varargout = elevator2(varargin)
% ELEVATOR2 MATLAB code for elevator2.fig
%      ELEVATOR2, by itself, creates a new ELEVATOR2 or raises the existing
%      singleton*.
%
%      H = ELEVATOR2 returns the handle to a new ELEVATOR2 or the handle to
%      the existing singleton*.
%
%      ELEVATOR2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ELEVATOR2.M with the given input arguments.
%
%      ELEVATOR2('Property','Value',...) creates a new ELEVATOR2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before elevator2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to elevator2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help elevator2

% Last Modified by GUIDE v2.5 29-Nov-2018 06:52:48

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @elevator2_OpeningFcn, ...
                   'gui_OutputFcn',  @elevator2_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT
end


% --- Executes just before elevator2 is made visible.
function elevator2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to elevator2 (see VARARGIN)

% Choose default command line output for elevator2
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes elevator2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);
end


% --- Outputs from this function are returned to the command line.
function varargout = elevator2_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
end

% --- Executes on button press in connection.
function connection_Callback(hObject, eventdata, handles)
% hObject    handle to connection (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.bt = Bluetooth('HC-06', 1);
fopen(handles.bt);

display('connected');

% q=fscanf(handles.bt, '%d');
% % w=fscanf(handles.bt, '%d');
% % h=fscanf(handles.bt, '%d');
% if (q=='|')
%     q=q
% end
% 
% if (w=='|')
%     w=w
% end
% 
% if (h=='|')
%     h=h
% end
%elevatorstates = zeros (1,3);%q=fscanf(handles.bt, '%d')fscanf(handles.bt)str2double(
%  for i = 1:3
%     elevatorstates(i) = fscanf(handles.bt, '%d');
%  end
%%%%%%%fwrite(handles.bt,4);
handles.elevator=fscanf(handles.bt, '%d');%elevatorstates(1)
%5555%%555555555555555%fwrite(handles.bt,4);
handles.floors=str2double(fscanf(handles.bt, '%d'));%elevatorstates(2)
%666666666666666666666666fwrite(handles.bt,4);
handles.direction=str2double(fscanf(handles.bt, '%d'));%elevatorstates(3)
guidata(hObject, handles);
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fwrite(handles.bt,4);
q=fscanf(handles.bt, '%d')
destination=4;
switch  handles.elevator
    case 1
%   if( handles.direction==0)
%     for n =handles.floors:-1:destination
%        set(handles.edit1,'string',num2str(n));
%         pause(.5)
%     end
if(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
 end
    case 2
%      if( handles.direction==0)
%     for n =handles.floors:-1:destination
%        set(handles.edit2,'string',num2str(n));
%         pause(.5)
%     end
    if(handles.direction==1)
    for n = floors:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
     end
    case 3
%        if( handles.direction==0)
%     for n =handles.floors:-1:destination
%        set(handles.edit3,'string',num2str(n));
%         pause(.5)
%     end
    if(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
    end
end
guidata(hObject, handles);

end






% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%fprintf(handles.b,'%d' ,3);
fwrite(handles.bt,3);
q=fscanf(handles.bt, '%d')
destination=3;
switch  handles.elevator
    case 1
  if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
   end
    case 2
     if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = floors:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
     end
    case 3
       if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
       end
end
guidata(hObject, handles);

end



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%fprintf(handles.b,'%d' ,2);
fwrite(handles.bt,2);
q=fscanf(handles.bt, '%d');
destination=2;
switch  handles.elevator
    case 1
  if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
   end
    case 2
     if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = floors:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
     end
    case 3
       if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
       end
end
guidata(hObject, handles);

end



% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
%fprintf(handles.b,'%d' ,1);
fwrite(handles.bt,1);
q=fscanf(handles.bt, '%d')
destination=1;
switch  handles.elevator
    case 1
  if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
   end
    case 2
     if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = floors:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
     end
    case 3
       if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==1)
    for n = handles.floors:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
       end
end
guidata(hObject, handles);
end



% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)end
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

%fprintf(handles.b,'%d' ,0);
fwrite(handles.bt,0);
q=fscanf(handles.bt, '%d')
destination=0;
switch  handles.elevator
    case 1
  if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
% elseif(handles.direction==1)
%     for n = handles.floors:destination
%        set(handles.edit1,'string',num2str(n));
%         pause(.5)
%     end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
   end
    case 2
     if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
% elseif(handles.direction==1)
%     for n = floors:destination
%        set(handles.edit2,'string',num2str(n));
%         pause(.5)
%     end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
     end
    case 3
       if( handles.direction==0)
    for n =handles.floors:-1:destination
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
% elseif(handles.direction==1)
%     for n = handles.floors:destination
%        set(handles.edit3,'string',num2str(n));
%         pause(.5)
%     end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
       end
end
guidata(hObject, handles);
end



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double
end

% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
end


function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double
end

% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

end

function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double
end

% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
end





% function elevator3( floors,direction,destination )
% %UNTITLED2 Summary of this function goes here
% %   Detailed explanation goes here
% 
%   
%        if( direction==0)
%     for n =floors:-1:destination
%        set(handles.edit3,'string',num2str(n));
%         pause(.5)
%     end
% elseif(direction==1)
%     for n = floors:destination
%        set(handles.edit3,'string',num2str(n));
%         pause(.5)
%     end
% %else(handles.floors==2)
%    %  set(handles.text2,'string',num2str(2));
%        end
%         guidata(hObject, handles);
% end
