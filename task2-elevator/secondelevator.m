function varargout = secondelevator(varargin)
% SECONDELEVATOR MATLAB code for secondelevator.fig
%      SECONDELEVATOR, by itself, creates a new SECONDELEVATOR or raises the existing
%      singleton*.
%
%      H = SECONDELEVATOR returns the handle to a new SECONDELEVATOR or the handle to
%      the existing singleton*.
%
%      SECONDELEVATOR('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SECONDELEVATOR.M with the given input arguments.
%
%      SECONDELEVATOR('Property','Value',...) creates a new SECONDELEVATOR or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before secondelevator_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to secondelevator_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help secondelevator

% Last Modified by GUIDE v2.5 29-Nov-2018 12:11:12

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @secondelevator_OpeningFcn, ...
                   'gui_OutputFcn',  @secondelevator_OutputFcn, ...
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


% --- Executes just before secondelevator is made visible.
function secondelevator_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to secondelevator (see VARARGIN)

% Choose default command line output for secondelevator
%handles.output = hObject;
handles.output = hObject;
guidata(hObject, handles);
instrhwinfo('Bluetooth');
handles.b=Bluetooth('HC-06',1);
fopen(handles.b);


% fwrite(b,10);
%   handles.elevator=fscanf(b,'%d');
%   fwrite(b,20);
%   handles.floor=fscanf(b,'%d');
%   fwrite(b,30);
%   handles.direction=fscanf(b,'%d');
handles.elevatorstates = zeros (1,3);
for i = 1:3
   elevatorstates(i) = str2double (fscanf(handles.b));
end
 handles.elevator=elevatorstates(1)
 handles.floor=elevatorstates(2)
  handles.direction=elevatorstates(3)
% Update handles structure



% UIWAIT makes secondelevator wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = secondelevator_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;




%function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
% function edit1_CreateFcn(hObject, eventdata, handles)
% % hObject    handle to edit1 (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    empty - handles not created until after all CreateFcns called
% 
% % Hint: edit controls usually have a white background on Windows.
% %       See ISPC and COMPUTER.
% if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
%     set(hObject,'BackgroundColor','white');
% end



%function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
% function edit2_CreateFcn(hObject, eventdata, handles)
% % hObject    handle to edit2 (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    empty - handles not created until after all CreateFcns called
% 
% % Hint: edit controls usually have a white background on Windows.
% %       See ISPC and COMPUTER.
% if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
%     set(hObject,'BackgroundColor','white');
% end



%function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit3 as text
%        str2double(get(hObject,'String')) returns contents of edit3 as a double


% --- Executes during object creation, after setting all properties.
% function edit3_CreateFcn(hObject, eventdata, handles)
% % hObject    handle to edit3 (see GCBO)
% % eventdata  reserved - to be defined in a future version of MATLAB
% % handles    empty - handles not created until after all CreateFcns called
% 
% % Hint: edit controls usually have a white background on Windows.
% %       See ISPC and COMPUTER.
% if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
%     set(hObject,'BackgroundColor','white');
% end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf(handles.b,'%d' ,0);
switch  handles.elevator
    case 1
  
if( handles.direction==1)
    for n =handles.floors:-1:0
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:0
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
end
 
    case 2
        if( handles.direction==1)
    for n =handles.floors:-1:0
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:0
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
    case 3
        if( handles.direction==1)
    for n =handles.floors:-1:0
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:0
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
end
guidata(hObject, handles);




% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf(handles.b,'%d' ,1);
switch  handles.elevator
    case 1
  
if( handles.direction==1)
    for n =handles.floors:-1:1
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:1
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
end
 
    case 2
        if( handles.direction==1)
    for n =handles.floors:-1:1
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:1
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
    case 3
        if( handles.direction==1)
    for n =handles.floors:-1:1
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:1
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
end
guidata(hObject, handles);



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf(handles.b,'%d' ,2);
switch  handles.elevator
    case 1
  
if( handles.direction==1)
    for n =handles.floors:-1:2
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:2
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
end
 
    case 2
        if( handles.direction==1)
    for n =handles.floors:-1:2
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:2
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
    case 3
        if( handles.direction==1)
    for n =handles.floors:-1:2
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:2
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
end
guidata(hObject, handles);



% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf(handles.b,'%d' ,3);
switch  handles.elevator
    case 1
  
if( handles.direction==1)
    for n =handles.floors:-1:3
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:3
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
end
 
    case 2
        if( handles.direction==1)
    for n =handles.floors:-1:3
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:3
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
    case 3
        if( handles.direction==1)
    for n =handles.floors:-1:3
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:3
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
end
guidata(hObject, handles);




% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
fprintf(handles.b,'%d' ,4);
switch  handles.elevator
    case 1
  
if( handles.direction==1)
    for n =handles.floors:-1:4
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:4
       set(handles.edit1,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
end
 
    case 2
        if( handles.direction==1)
    for n =handles.floors:-1:4
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:4
       set(handles.edit2,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
    case 3
        if( handles.direction==1)
    for n =handles.floors:-1:4
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
elseif(handles.direction==0)
    for n = handles.floors:4
       set(handles.edit3,'string',num2str(n));
        pause(.5)
    end
%else(handles.floors==2)
   %  set(handles.text2,'string',num2str(2));
        end
end

guidata(hObject, handles);
end
