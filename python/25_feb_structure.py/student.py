students =[ ["Ben",{"Maths":67,"english":78,"Science":72}],
            ["Mark",{"Maths":68,"Art":64,"History":39,"Geography":55}],
            ["paul",{"English":58,"History":88}]]

grades = ((0,"FAIL"),(50,"D"),(60,"C"),(70,"B"),(80,"A"),(101,"CHEAT!"))


def print_report_card(report_student=None) :
    for student in students:
        prev_grade="NOT Defined"
        if(student[0]==report_student) or (report_student==None):
            print("Report card for student ",student[0])
            for subject,mark in student[1].items() :
                for grade in grades:
                    if mark < grade[0]:
                        print(subject,":",prev_grade)
                        break
                    prev_grade=grade[1]
                



def add_student(student_name):
    global students
    for student in students:
        if student[0]==student_name:
            return "student already in database"

    students.append([student_name,{}])
    return "student added successfully"

def add_mark(student_name,subject,mark):
    global students
    for student in students:
        if student[0]==student_name:
            if subject in student[1].keys():
                print(student_name,"already has a mark for",subject)
                user_input==input("overwrite Y/N?")
                if user_input=="Y" or "y":
                    student[1][subject]=mark
                    return "Student's mark updated"
                else:
                    return "student's mark not updated"
            else:
                student[1][subject]=mark
                return "Student's mark added"
    return "student not found"

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
        print_report_card()
    elif user_choice==2:
        enter_student=input("which student? ")
        print_report_card(enter_student)
    elif user_choice==3:
        enter_student=input("student name? ")
        print(add_student(enter_student))
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
        print(add_mark(enter_student,enter_subject,enter_mark))
    elif user_choice==5:
        break
    else:
        print("unknown choice")
#    input("press enter to continue")
print("Goodbye and thank you for using raspberry pi","student database")



