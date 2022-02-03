# CI-V-to-IC-7300-with-Arduino-Uno

<b> ++++ ERROR - The D0 and D1 ports you can NOT use for I/O of the CI-V bus if USB connection (serial) is active ++++ </b><br>

Update:

Ad a. To see result of the code when D0 and D1 pins are used you can use an 4 lines I2C LCD display [3]. <br>
After downloading the code to the Arduino, disconnect the USB upload cable and use external power.<br>
On the LCD you can see the result of the CI-V code.<p>

Ad b. In test we will switch later to the TFT screen communication as wanted before.<br>
On that place we use again the D0 and D1 pin.<p>

This repository will give information (also for beginner Ham) to use the remote port (CI-V stands for Communications Interface 5) on the IC-7300 transceiver to the Arduino UNO with or without TFT screen (in development !)

Looking inside the menu of the IC-7300 you will find the CI-V settings.<br>
To communicate via the USB-CI-V commands you can use the address 00h.<br>
To communicate via the remote connector you can use the address 94h.<br>
* The 'CI-V transceive' you can leave, this option you can use to connect two IC-7300 together via the remote connection line.<br>
* The 'CI-V Output (Ant)' will give via the remote port freq. and band info to an remote antenna selector (may be use in our project).<br> 
* The 'CI-V USB port / Link or Unlink from remote port' - remote and USB commands will give the same results to USB and remote port <br>
  in our project we will leave set this in the 'unlink' status.<p>
  
First of all we need a small part of hardware interface.<br>
This schema will make the connection.

![image](https://user-images.githubusercontent.com/4719917/152031252-81abdf0e-3988-4e99-84fb-821411a88f9b.png)


What are the basics to use the interface, a good readable webpage is at [1].<br>
We have to 'ask' the rig to do something with an command, in the *.ino code we will explain this by comment code.<p>

<b>Used links:</b><br>
  [1] https://kb3hha.com/ArticleDetails?id=6 <br>
  [2] https://jj1jpm.at.webry.info/201608/article_1.html<br>
  [3] https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/


  



