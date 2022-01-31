# CI-V-to-IC-7300-with-Arduino-Uno
This repository will give information (also for beginner Ham) to use the remote port (IC-V) on the IC-7300 transceiver to the Arduino UNO

Looking inside the menu of the IC-7300 you will find the CI-V settings.<br>
To communicate via the USB-CI-V commands you can use the address 00h.<br>
To communicate via the remote connector you can use the address 94h.<br>
The 'CI-V transceive' you can leave, this option you can use to connect two IC-7300 together via the remote connection line.<br>
The 'CI-V Output (Ant)' will give via the remote port freq. and band info to an remote antenna selector (may be use in our project).<p> 
  
First of all we need a small part of hardware interface.<br>
This schema will make the connection.
  
![image](https://user-images.githubusercontent.com/4719917/151844038-b9bdd832-afc1-4234-8623-0a687355c0c4.png)


  



