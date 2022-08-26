JC = javac
R = java
SUB = aka/src/
DRIVER = Driver
JFlags = 


run:
	$(JC)  $(SUB)*.java $(DRIVER).java -d classfiles
	$(R) -cp classfiles $(DRIVER)

javadoc:
	javadoc $(SUB)*.java -d javadoc

clean:
	rm javadoc/ classfiles/ -r


