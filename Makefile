NAME		=	ft_vox

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

ifdef		__APPLE_CC__
GLFLAGS		=	-framework OpenGL -framework GLUT
else
GLFLAGS		=	-lGL -lGLU -lglut
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
