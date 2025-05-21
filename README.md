# **StegShield:** A Least Significant Bit Stegenography program.

A **Stegenography** app that hides text within the **Least Significant Bits** *(LSBs)* of an image implemented in QT6 C++.<br/>
This program only accepts *PNG* type images, and the text is stored in the first bit of each color<br/>
of the *RGB* color model, which means that each *pixel* stores 3 *bits* of data.<br/>
You can calculate the maximum possible size of the stored text by using this equation:<br/>
###              max_text_size (Bytes) = (image.width (pixels) * image.hight (pixels) * 3) / 8
The program adds "/DONE" to the end of the given text to help indicate the end of the hidden text<br/>
so that the program want continue decoding the remaining LSBs of the image.<br/>
If you find any issue contact me on this e-mail: *ahmadestanboly5@gmail.com*<br/>
