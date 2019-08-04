function varargout = elevator1(varargin)
% ELEVATOR1 MATLAB code for elevator1.fig
%      ELEVATOR1, by itself, creates a new ELEVATOR1 or raises the existing
%      singleton*.
%
%      H = ELEVATOR1 returns the handle to a new ELEVATOR1 or the handle to
%      the existing singleton*.
%
%      ELEVATOR1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ELEVATOR1.M with the given input arguments.
%
%      ELEVATOR1('Property','Value',...) creates a new ELEVATOR1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before elevator1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to elevator1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help elevator1

% Last Modified by GUIDE v2.5 10-Oct-2018 18:17:25

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @elevator1_OpeningFcn, ...
                   'gui_OutputFcn',  @elevator1_OutputFcn, ...
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


% --- Executes just before elevator1 is made visible.
function elevator1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to elevator1 (see VARARGIN)

% Choose default command line output for elevator1
instrhwinfo('Bluetooth')
handles.b=Bluetooth('HC-06',1);
fopen(handles.b);
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes elevator1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = elevator1_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf(handles.b,'%d' ,1);
out = fscanf(handles.b,'%d');
if(out>1)
    for n = out:-1:1
       set(handles.text2,'string',num2str(n));
        pause(.5)
   end
elseif (out==1)
     set(handles.text2,'string',num2str(1));
 end

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf(handles.b, '%d', 2);
out = fscanf(handles.b,'%d')
if(out>2)
    for n = out:-1:2
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
elseif(out<2)
    for n = out:2
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
else(out==2)
     set(handles.text2,'string',num2str(2));
 end



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf(handles.b, '%d', 3);
out = fscanf(handles.b,'%d')
if(out>3)
    for n = out:-1:3
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
elseif(out<3)
    for n = out:3
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
else (out==3)
     set(handles.text2,'string',num2str(3));
 end


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf(handles.b, '%d', 4);
out = fscanf(handles.b,'%d')
if(out>4)
    for n = out:-1:4
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
elseif(out<4)
    for n = out:4
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
else (out==4)
     set(handles.text2,'string',num2str(4));
 end


% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf(handles.b, '%d',5);
out = fscanf(handles.b,'%d')

if(out<5)
    for n = out:5
       set(handles.text2,'string',num2str(n));
        pause(.5)
    end
elseif (out==5)
     set(handles.text2,'string',num2str(5));
 end

