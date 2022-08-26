JC = javac
R = java
SUPER = interfaceAka/
SUB = srcAka/
DRIVER = test
JFlags = 


run:
	$(JC) $(JFlags) $(SUPER)*.java $(SUB)*.java $(DRIVER).java  -d classfiles
	$(R) -cp classfiles $(DRIVER)

javadoc:
	javadoc $(SUPER)*.java $(SUB)*.java -d javadoc

clean:
	rm javadoc/ classfiles/ -r

