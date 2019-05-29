student_data= [["Ben",{"maths":67,"English":78 ,"Science": 72}],
        ["Mark",{"Maths":56,"Art":64, "History":39, "Geography":55}],
        ["Paul",{"English":66,"History":88}]]

grades =((0,"FAIL"),(50,"D"),(60,"C"),(70,"B"),(80,"A"),(110,"CHEAT"))

class Student() :
    def __init__(self,name,marks):
        self.name=name
        self.marks=marks

    def print_report_card(self):
        print("Report card for student ",self.name)
        for subject,mark in self.marks.items():
            for i in grades:
                if mark < i[0] :
                    print(subject," : ",prev_grade)
                    break
                prev_grade=i[1]

    def add_mark(self,subject,mark):
        if subject in self.marks.keys() :
            print(self.name,"already has a mark for ",subject)
            user_input=input("overwrite Y/N ");
            if user_input == "Y" or "y":
                self.marks[subject]=mark
                return "student's mark updated"
            else:
                return "student's mark not updated"

        else:
            self.marks[subject]=mark
            return "student's mark added"


class Students():
    def __init__(self,all_students):
        self.students=[]
        for student,mark in all_students:
            self.add_student(student,mark)

    def add_student(self,student_name,marks={}):
        if self.exists(student_name):
            return "students already in database"
        else:
            self.students.append(Student(student_name,marks)) # calling to Student class
            return "student added"

    def print_report_cards(self,student_name=None) :
        for student in self.students:
            if student_name==None or student.name :
                student.print_report_card()

    def exists(self,student_name):
        for student in self.students:
            if student_name==student.name:
                return True
            return False

    def add_mark(self,student_name,subject,mark):
        for student in self.students:
            if student_name == student.name:
                return student.add_mark(subject,mark)
        return "student not found"

students =Students(student_data)
print(students.students)

while True:
    print("Welcome to the rpi student database")
    print("what can i help you with?")
    print("enter 1 to view all report cards")
    print("enter 2 to view  report card for a student")
    print("enter 3 to add a student")
    print("enter 4 to add a mark to  a student")
    print("enter 5 to exit")

    try:
        user_choice=int(input("choice:"))
    except ValuError:
        print("that's not a number")
        user_choice=0

    if user_choice==1:
       students.print_report_cards()
                                                                                
    elif user_choice==2:
        enter_student=input("which student? ")
        students.print_report_cards(enter_student)
    elif user_choice==3:
        enter_student=input("student name? ")
        print(students.add_student(enter_student))
    elif user_choice==4:
        enter_student=input("student name? ")
        enter_subject=input("subject? ")
        num_error=True
        while num_error:
            num_error=False
            try:
                enter_mark=int(input("Mark?"))
            except ValueError:
                print("I don't recognize that as a number")
                num_error=True
        print(students.add_mark(enter_student,enter_subject,enter_mark))
    elif user_choice==5:
        break
    else:
        print("unknown choice")
#    input("press enter to continue")
print("Goodbye and thank you for using raspberry pi","student database")

                                                                                                                                    
