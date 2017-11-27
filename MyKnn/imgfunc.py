from PIL import Image
import os
import numpy as np

def load_lots_img(path,x,y):
	#x=50
	#y=50
	imgs=os.listdir(path)
	imgnum=len(imgs)

	data=np.empty((imgnum,x,y),dtype="uint8")
	label=np.empty((imgnum,),dtype="uint8")
	#arr=np.empty((x,y),dtype="uint8")
	for i in range(imgnum):
		img=Image.open(path+'/'+imgs[i])
		arr=np.asarray(img,dtype="uint8")
		arr_new=arr[:x,:y]
		data[i,:,:]=arr_new
		label[i]=int(imgs[i].split('_')[0])
		
	return data,label
	

def rand_train_data(path,j,k,num_tr,num_te):
	x_tr=np.empty((0,j,k),dtype="uint8")
	y_tr=np.empty((0,),dtype="uint8")
	x_te=np.empty((0,j,k),dtype="uint8")
	y_te=np.empty((0,),dtype="uint8")
	for i in range(6):
		newpath=path+'/batch'+str(i+1)
		
		x_ori,y_ori=load_lots_img(newpath,j,k)
		x_tr=np.concatenate((x_tr,x_ori[:num_tr,:,:]))
		y_tr=np.concatenate((y_tr,y_ori[:num_tr,]))
		x_te=np.concatenate((x_te,x_ori[num_tr:num_tr+num_te,:,:]))
		y_te=np.concatenate((y_te,y_ori[num_tr:num_tr+num_te,]))
		
	return x_tr,y_tr,x_te,y_te
		
		
