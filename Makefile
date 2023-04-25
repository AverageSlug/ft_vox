NAME		=	ft_vox

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

UNAME := $(shell uname -s)

ifeq ($(UNAME), Linux)
	GLFLAGS		=	-lGL -lGLU -lglut
else
	GLFLAGS		=	-framework OpenGL -framework GLUT
endif

SRCS		=	$(wildcard *.cpp)

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(GLFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all
