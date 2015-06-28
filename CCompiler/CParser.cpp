/* A Bison parser, made by GNU Bison 2.7.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */
/* Line 279 of lalr1.cc  */
#line 6 "CParser.y"

#include <stdio.h>
#include <string>
#include "CParserDriver.h"
#include "SyntaxNode.h"

Program* program;


/* Line 279 of lalr1.cc  */
#line 48 "CParser.cpp"


#include "CParser.hpp"

/* User implementation prologue.  */
/* Line 285 of lalr1.cc  */
#line 131 "CParser.y"


extern int yylex(yy::CParser::semantic_type *yylval, 
	yy::CParser::location_type *yylloc, CParserDriver& driver);

/* Line 285 of lalr1.cc  */
#line 62 "CParser.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
/* Line 353 of lalr1.cc  */
#line 157 "CParser.cpp"

  /// Build a parser object.
  CParser::CParser (CParserDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  CParser::~CParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  CParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  CParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  CParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  CParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  CParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  CParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  CParser::debug_level_type
  CParser::debug_level () const
  {
    return yydebug_;
  }

  void
  CParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  CParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  CParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  CParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
        YYCDEBUG << "Reading a token: ";
        yychar = yylex (&yylval, &yylloc, driver);
      }

    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 2:
/* Line 670 of lalr1.cc  */
#line 139 "CParser.y"
    { (yyval.program) = (yysemantic_stack_[(1) - (1)].program); driver.set_program((yysemantic_stack_[(1) - (1)].program)); }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 143 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].identifier); }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 144 "CParser.y"
    { 
		(yyval.expression) = new ImmediateInteger(atol((yysemantic_stack_[(1) - (1)].str)->c_str())); 
		delete (yysemantic_stack_[(1) - (1)].str);
	}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 148 "CParser.y"
    {
		std::string str = "";
		char c;
		for (std::size_t i = 0; i < (yysemantic_stack_[(1) - (1)].str)->length(); i++)
		{
			if ((*(yysemantic_stack_[(1) - (1)].str))[i] == '\\')
			{
					switch((*(yysemantic_stack_[(1) - (1)].str))[++i])
				{
					case '0':
						c = '\0'; break;
					case 'n':
						c = '\n'; break;
					case 'r':
						c = '\r'; break;
					case 't':
						c = '\t'; break;
					case '\\':
						c = '\\'; break;
					case '\'':
						c = '\''; break;
					case '\"':
						c = '\"'; break;
					default:
						break;
				}
			}
			else c = (*(yysemantic_stack_[(1) - (1)].str))[i];
			str += c;
		}
		(yyval.expression) = new StringLiteral(str);
		delete (yysemantic_stack_[(1) - (1)].str);
	}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 181 "CParser.y"
    {
		char c;
		if ((yysemantic_stack_[(1) - (1)].str)->length() == 3)
			c = (*(yysemantic_stack_[(1) - (1)].str))[1];
		else
		{
			char temp = (*(yysemantic_stack_[(1) - (1)].str))[2];
			switch(temp)
			{
				case '0':
					c = '\0'; break;
				case 'n':
					c = '\n'; break;
				case 'r':
					c = '\r'; break;
				case 't':
					c = '\t'; break;
				case '\\':
					c = '\\'; break;
				case '\'':
					c = '\''; break;
				case '\"':
					c = '\"'; break;
				default:
					break;
			}
		}
		(yyval.expression) = new CharLiteral(c);
		delete (yysemantic_stack_[(1) - (1)].str);
	}
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 211 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 212 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::ADD); }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 213 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SUB); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 214 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::MUL); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 215 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::DIV); }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 216 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::MOD); }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 217 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::XOR_BIT); }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 218 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::OR_BIT); }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 219 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::AND_BIT); }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 220 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_LEFT); }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 221 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_RIGHT); }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 222 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::GREATER); }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 223 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::LESS); }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 224 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::EQUAL); }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 225 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::LESS_EQUAL); }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 226 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::GREATER_EQUAL); }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 227 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::NOT_EQUAL); }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 228 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::ASSIGN); }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 229 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::ADD_ASSIGN); }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 230 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SUB_ASSIGN); }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 231 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::MUL_ASSIGN); }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 232 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::DIV_ASSIGN); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 233 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::MOD_ASSIGN); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 234 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::AND_ASSIGN); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 235 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::EXCLUSIVE_OR_ASSIGN); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 236 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::INCLUSIVE_OR_ASSIGN); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 237 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_LEFT_ASSIGN); }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 238 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_RIGHT_ASSIGN); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 239 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::AND); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 240 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::OR); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 241 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (3)].expression), BinaryExpression::Operator::INDEX); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 242 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::DOT); }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 243 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::POINTER); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 244 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (1)].expression), UnaryExpression::Operator::INC_AFTER); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 245 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (1)].expression), UnaryExpression::Operator::DEC_AFTER); }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 246 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::INC_PRE); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 247 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::DEC_PRE); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 248 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::REFERENCE); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 249 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::DEREFERENCE); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 250 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(2) - (2)].expression); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 251 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::MINUS); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 252 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::NOT_BIT); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 253 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::NOT); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 254 "CParser.y"
    { (yyval.expression) = new FunctionCall((yysemantic_stack_[(4) - (1)].identifier), *((yysemantic_stack_[(4) - (3)].expression_list))); }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 255 "CParser.y"
    { (yyval.expression) = new FunctionCall((yysemantic_stack_[(3) - (1)].identifier), std::vector<Expression *>()); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 259 "CParser.y"
    { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yysemantic_stack_[(1) - (1)].expression)); }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 260 "CParser.y"
    { (yyval.expression_list)->push_back((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 289 "CParser.y"
    {
		for (auto iterator = (yysemantic_stack_[(2) - (2)].variable_declaration_list)->begin(); iterator != (yysemantic_stack_[(2) - (2)].variable_declaration_list)->end(); iterator++) {
			(*iterator)->set_basic_type((yysemantic_stack_[(2) - (1)].vt_t));
		}
		(yyval.variable_declaration) = *((yysemantic_stack_[(2) - (2)].variable_declaration_list)->begin());
	}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 298 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yysemantic_stack_[(1) - (1)].variable_declaration));
	}
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 302 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration_list)->push_back((yysemantic_stack_[(3) - (3)].variable_declaration));
		(yyval.variable_declaration_list) = (yysemantic_stack_[(3) - (1)].variable_declaration_list);
	}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 318 "CParser.y"
    {
		(yyval.variable_declaration) = (yysemantic_stack_[(3) - (1)].variable_declaration);
		(yyval.variable_declaration)->set_initializer((yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 325 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::VOID; }
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 326 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::CHARACTER; }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 327 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::INTEGER; }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 328 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::FLOAT; }
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 332 "CParser.y"
    { (yyval.number) = 0; }
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 333 "CParser.y"
    { (yyval.number) = (yysemantic_stack_[(2) - (2)].number) + 1; }
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 337 "CParser.y"
    {
		for (int i = 0; i < (yysemantic_stack_[(2) - (1)].number); i++) {
			(yysemantic_stack_[(2) - (2)].variable_declaration)->AddPointerSpecifier(); 
		}
		(yyval.variable_declaration) = (yysemantic_stack_[(2) - (2)].variable_declaration);
	}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 346 "CParser.y"
    {
		(yyval.variable_declaration) = new VariableDeclaration();
		(yyval.variable_declaration)->set_identifier((yysemantic_stack_[(1) - (1)].identifier));
	}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 350 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration)->AddArraySpecifier(nullptr);
		(yyval.variable_declaration) = (yysemantic_stack_[(3) - (1)].variable_declaration);
	}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 354 "CParser.y"
    {
		(yysemantic_stack_[(4) - (1)].variable_declaration)->AddArraySpecifier((yysemantic_stack_[(4) - (3)].expression)); 
		(yyval.variable_declaration) = (yysemantic_stack_[(4) - (1)].variable_declaration);
	}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 367 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration(*((yysemantic_stack_[(5) - (4)].variable_declaration_list)));
		(yysemantic_stack_[(5) - (2)].variable_declaration)->set_basic_type((yysemantic_stack_[(5) - (1)].vt_t));
		(yysemantic_stack_[(5) - (2)].variable_declaration)->SetAsFunctionDeclaration(*(yyval.function_declaration));
		delete (yysemantic_stack_[(5) - (4)].variable_declaration_list);
	}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 373 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration(std::vector<VariableDeclaration*>());
		(yysemantic_stack_[(4) - (2)].variable_declaration)->set_basic_type((yysemantic_stack_[(4) - (1)].vt_t));
		(yysemantic_stack_[(4) - (2)].variable_declaration)->SetAsFunctionDeclaration(*(yyval.function_declaration));
	}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 381 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yysemantic_stack_[(1) - (1)].variable_declaration));
	}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 385 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration_list)->push_back((yysemantic_stack_[(3) - (3)].variable_declaration));
		(yyval.variable_declaration_list) = (yysemantic_stack_[(3) - (1)].variable_declaration_list);
	}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 392 "CParser.y"
    {
		(yysemantic_stack_[(2) - (2)].variable_declaration)->set_basic_type((yysemantic_stack_[(2) - (1)].vt_t));
		(yyval.variable_declaration) = (yysemantic_stack_[(2) - (2)].variable_declaration);
	}
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 399 "CParser.y"
    { (yyval.identifier) = new Identifier(*(yysemantic_stack_[(1) - (1)].str)); }
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 404 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].array_initializer);}
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 411 "CParser.y"
    { 
		(yyval.array_initializer) = new ListInitializer();
		(yyval.array_initializer)->PushExpression((yysemantic_stack_[(1) - (1)].expression));
	}
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 415 "CParser.y"
    {
		(yyval.array_initializer)->PushExpression((yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 421 "CParser.y"
    { (yyval.statement) = new ExpressionStatement(nullptr); }
    break;

  case 88:
/* Line 670 of lalr1.cc  */
#line 429 "CParser.y"
    { (yyval.statement) = new DeclarationStatement((yysemantic_stack_[(2) - (1)].variable_declaration)); }
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 433 "CParser.y"
    {
		(yyval.statement) = (yysemantic_stack_[(3) - (2)].statement);
	}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 439 "CParser.y"
    {
		(yyval.statement) = new StatementsBlock();
		//((StatementsBlock *)$$)->PushStatement($1);
	}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 443 "CParser.y"
    {
		((StatementsBlock *)(yysemantic_stack_[(2) - (1)].statement))->PushStatement((yysemantic_stack_[(2) - (2)].statement));
		(yyval.statement) = (yysemantic_stack_[(2) - (1)].statement);
	}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 454 "CParser.y"
    {
		(yyval.statement) = new ExpressionStatement((yysemantic_stack_[(2) - (1)].expression));
	}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 460 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yysemantic_stack_[(5) - (3)].expression), (yysemantic_stack_[(5) - (5)].statement));
	}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 463 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yysemantic_stack_[(7) - (3)].expression), (yysemantic_stack_[(7) - (5)].statement), (yysemantic_stack_[(7) - (7)].statement));
	}
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 469 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yysemantic_stack_[(5) - (3)].expression), (yysemantic_stack_[(5) - (5)].statement));
	}
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 472 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yysemantic_stack_[(7) - (5)].expression), (yysemantic_stack_[(7) - (2)].statement), true);
	}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 479 "CParser.y"
    {
		(yyval.statement) = new ForStatement((yysemantic_stack_[(9) - (3)].expression), (yysemantic_stack_[(9) - (5)].expression), (yysemantic_stack_[(9) - (7)].expression), (yysemantic_stack_[(9) - (9)].statement));
	}
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 482 "CParser.y"
    {
		(yyval.statement) = new ForStatement((yysemantic_stack_[(9) - (3)].variable_declaration), (yysemantic_stack_[(9) - (5)].expression), (yysemantic_stack_[(9) - (7)].expression), (yysemantic_stack_[(9) - (9)].statement));
	}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 489 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::CONTINUE);
	}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 492 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::BREAK);
	}
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 498 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement((yysemantic_stack_[(3) - (2)].expression));
	}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 501 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement(nullptr);
	}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 511 "CParser.y"
    {
		(yyval.program) = new Program();
		(yyval.program)->PushDeclaration((yysemantic_stack_[(1) - (1)].declaration));
	}
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 515 "CParser.y"
    {
		(yyval.program)->PushDeclaration((yysemantic_stack_[(2) - (2)].declaration));
	}
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 521 "CParser.y"
    {
		(yyval.declaration) = (yysemantic_stack_[(1) - (1)].function_declaration);
	}
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 524 "CParser.y"
    {
		(yyval.declaration) = new GlobalVariableDeclaration((yysemantic_stack_[(2) - (1)].variable_declaration));
	}
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 530 "CParser.y"
    {
		(yysemantic_stack_[(2) - (1)].function_declaration)->set_body((yysemantic_stack_[(2) - (2)].statement));
		(yyval.function_declaration) = (yysemantic_stack_[(2) - (1)].function_declaration);
	}
    break;


/* Line 670 of lalr1.cc  */
#line 1163 "CParser.cpp"
      default:
        break;
      }

    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */
        if (yychar <= yyeof_)
          {
            /* Return failure if at end of input.  */
            if (yychar == yyeof_)
              YYABORT;
          }
        else
          {
            yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
            yychar = yyempty_;
          }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	  YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  // Generate an error message.
  std::string
  CParser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char CParser::yypact_ninf_ = -65;
  const short int
  CParser::yypact_[] =
  {
        -6,   -65,   -65,   -65,   -65,     4,   -48,   -64,   -65,   -49,
      -6,   -65,   -65,   -65,   -48,   -30,   -65,    28,   -38,   -65,
     -65,   -65,   -65,   -65,   -48,   -65,   -20,   -65,   121,   -17,
     160,   -65,     2,   627,   -65,   -65,   -65,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   121,  1200,   -18,   -65,
     -65,   -48,   -42,   -65,   -15,   -14,   216,   -13,   -12,   -11,
      51,   -65,   -65,   282,   -48,    30,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,  1082,    33,    33,    33,
      33,    33,    33,    33,    33,   716,   -65,   -33,   -65,   -65,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   571,   -65,   -65,    -6,   656,   656,    72,   600,
     -65,   -65,   -65,   348,   -65,   -65,   -65,   -65,   121,   -65,
     -65,  1406,  1406,   692,   692,  1444,  1444,  1297,  1279,  1221,
    1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,
    1355,  1371,  1386,   692,   692,   173,   173,   147,   147,   147,
     -65,  1141,   -65,  1200,   -24,   -65,   777,   838,    41,   414,
      39,   -65,   -65,   -65,   -65,   656,   216,   216,   656,   656,
     656,  1200,    81,   -65,   899,   480,   546,   216,    42,   656,
     656,   -65,   -65,   960,  1021,   216,   216,   -65,   -65
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  CParser::yydefact_[] =
  {
         0,    61,    62,    63,    60,     0,    64,     0,    54,     0,
       2,   104,   106,     1,    64,    55,    56,     0,    58,   107,
      90,   108,   105,    65,    64,    75,    66,    67,     0,     0,
       0,    57,    58,     0,     5,     4,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     3,    59,
      71,    64,     0,    72,     0,     0,     0,     0,     0,     0,
       0,    89,    80,     0,    64,     0,    92,    81,    91,    82,
      83,    84,    85,    86,    87,    68,     0,    42,    43,    44,
      46,    47,    45,    49,    48,     0,    78,     0,    40,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    70,     0,     0,     0,     0,     0,
     100,   101,   103,     0,    93,    88,    69,     7,     0,    77,
      39,    16,    17,    21,    22,    20,    23,    35,    36,    25,
      26,    27,    28,    29,    33,    34,    30,    32,    31,    24,
      14,    13,    15,    18,    19,     8,     9,    11,    10,    12,
      38,     0,    51,    52,     0,    73,     0,     0,     0,     0,
       0,   102,    79,    37,    50,     0,     0,     0,     0,     0,
       0,    53,    94,    96,     0,     0,     0,     0,     0,     0,
       0,    95,    97,     0,     0,     0,     0,    98,    99
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  CParser::yypgoto_[] =
  {
       -65,   -65,   -28,   -65,    20,    19,   -65,    89,   -65,   101,
      -4,   -65,   -65,   -65,    -9,   102,   -43,   -65,   -55,   109,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   110,
     -65
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  CParser::yydefgoto_[] =
  {
        -1,     5,    63,   174,    64,    65,    15,    16,     8,    17,
      32,    26,     9,    52,    53,    48,    49,    87,    66,    67,
      30,    68,    69,    70,    71,    72,    73,    74,    10,    11,
      12
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char CParser::yytable_ninf_ = -1;
  const short int
  CParser::yytable_[] =
  {
        47,   128,    18,    86,    13,    76,    28,    14,    19,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    47,     7,
       6,    20,     1,     2,     3,   124,     4,   125,    29,     7,
       6,    25,   133,     1,     2,     3,   138,     4,   139,    24,
      -1,    -1,    90,   184,    33,   185,    28,   123,   122,    51,
      50,   126,   127,   129,    25,    34,    35,    36,    37,    38,
     130,   131,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   173,   182,   120,   121,   176,   177,
      39,   179,   135,    40,    41,   178,    42,   188,    43,    44,
      47,   190,   197,    31,   202,    23,   175,    45,    21,    27,
      22,     0,     0,   132,    25,    34,    35,    36,    37,    38,
       0,   192,   193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,     0,     0,    51,     0,     0,   180,     0,
     207,   208,     0,     0,    88,    89,    90,   191,     0,     0,
     194,   195,   196,    25,    34,    35,    36,    37,    38,     0,
      39,   203,   204,    40,    41,     0,    42,     0,    43,    44,
      88,    89,    90,     0,     0,     0,     0,    45,     0,     0,
      54,    46,     0,    55,    56,    57,    58,    59,    60,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     0,    39,
     120,   121,    40,    41,     0,    42,     0,    43,    44,    25,
      34,    35,    36,    37,    38,     0,    45,   117,   118,   119,
      20,    61,    62,     0,     0,     0,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,     0,    55,
      56,    57,    58,    59,    60,     1,     2,     3,     0,     4,
       0,     0,     0,     0,     0,    39,     0,     0,    40,    41,
       0,    42,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,    20,     0,    62,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,   134,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
     181,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,   120,   121,     0,
       0,     0,     0,     0,     0,     0,   189,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,     0,     0,     0,     0,     0,
       0,     0,   199,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    25,    34,    35,    36,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    25,    34,    35,    36,    37,    38,   120,
     121,     0,     0,     0,     0,     0,     0,     0,   200,     0,
      39,     0,     0,    40,    41,     0,    42,     0,    43,    44,
      25,    34,    35,    36,    37,    38,     0,    45,   172,     1,
       2,     3,     0,     4,     0,     0,     0,     0,     0,    39,
       0,     0,    40,    41,     0,    42,     0,    43,    44,    25,
      34,    35,    36,    37,    38,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    40,
      41,     0,    42,     0,    43,    44,     0,     0,     0,     0,
       0,     0,    75,    45,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,     0,    39,     0,     0,    40,    41,
       0,    42,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,    45,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,   120,   121,     0,     0,     0,
     109,     0,     0,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,     0,     0,     0,     0,     0,     0,   120,
     121,     0,     0,   137,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
     120,   121,     0,     0,   186,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,     0,     0,     0,     0,     0,
       0,   120,   121,     0,     0,   187,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,   120,   121,     0,     0,   198,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,     0,     0,   205,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,   120,   121,     0,     0,   206,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     0,
       0,     0,     0,     0,     0,   120,   121,   136,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,   120,   121,   183,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,   109,     0,     0,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,     0,     0,     0,
       0,     0,     0,   120,   121,     0,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,   120,   121,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,     0,
       0,     0,   120,   121,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,     0,     0,     0,     0,     0,     0,
     120,   121,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,     0,    88,    89,    90,     0,     0,   120,   121,
     112,   113,   114,   115,   116,   117,   118,   119,     0,     0,
       0,     0,     0,     0,   120,   121,   113,   114,   115,   116,
     117,   118,   119,     0,     0,     0,     0,     0,     0,   120,
     121,    88,    89,    90,    91,    92,    93,    94,   115,   116,
     117,   118,   119,     0,     0,     0,     0,     0,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,     0,     0,     0,     0,     0,     0,   120,   121
  };

  /* YYCHECK.  */
  const short int
  CParser::yycheck_[] =
  {
        28,    56,     6,    46,     0,    33,    44,    55,    72,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
       0,    70,    39,    40,    41,    67,    43,    69,    66,    10,
      10,     3,    60,    39,    40,    41,    69,    43,    71,    69,
       7,     8,     9,    67,    64,    69,    44,    51,    66,    29,
      67,    66,    66,    66,     3,     4,     5,     6,     7,     8,
      72,    72,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   138,    63,    64,   126,   127,
      49,   129,    72,    52,    53,    33,    55,    66,    57,    58,
     138,    72,    31,    24,    72,    14,   125,    66,     9,    17,
      10,    -1,    -1,    72,     3,     4,     5,     6,     7,     8,
      -1,   186,   187,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,    -1,   125,    -1,    -1,   129,    -1,
     205,   206,    -1,    -1,     7,     8,     9,   185,    -1,    -1,
     188,   189,   190,     3,     4,     5,     6,     7,     8,    -1,
      49,   199,   200,    52,    53,    -1,    55,    -1,    57,    58,
       7,     8,     9,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      30,    70,    -1,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      63,    64,    52,    53,    -1,    55,    -1,    57,    58,     3,
       4,     5,     6,     7,     8,    -1,    66,    54,    55,    56,
      70,    71,    72,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    53,
      -1,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    70,    -1,    72,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     3,     4,     5,     6,     7,     8,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      49,    -1,    -1,    52,    53,    -1,    55,    -1,    57,    58,
       3,     4,     5,     6,     7,     8,    -1,    66,    67,    39,
      40,    41,    -1,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    -1,    55,    -1,    57,    58,     3,
       4,     5,     6,     7,     8,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    -1,    49,    -1,    -1,    52,    53,
      -1,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    67,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    67,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    67,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    67,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    67,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,     7,     8,     9,    -1,    -1,    63,    64,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,     7,     8,     9,    10,    11,    12,    13,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CParser::yystos_[] =
  {
         0,    39,    40,    41,    43,    74,    77,    78,    81,    85,
     101,   102,   103,     0,    55,    79,    80,    82,    83,    72,
      70,    92,   102,    82,    69,     3,    84,    88,    44,    66,
      93,    80,    83,    64,     4,     5,     6,     7,     8,    49,
      52,    53,    55,    57,    58,    66,    70,    75,    88,    89,
      67,    77,    86,    87,    30,    33,    34,    35,    36,    37,
      38,    71,    72,    75,    77,    78,    91,    92,    94,    95,
      96,    97,    98,    99,   100,    65,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    89,    90,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    44,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      63,    64,    66,    83,    67,    69,    66,    66,    91,    66,
      72,    72,    72,    75,    72,    72,    65,    67,    69,    71,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    67,    75,    76,    87,    75,    75,    33,    75,
      78,    72,    89,    65,    67,    69,    67,    67,    66,    72,
      72,    75,    91,    91,    75,    75,    75,    31,    67,    72,
      72,    91,    72,    75,    75,    67,    67,    91,    91
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  CParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    61,   299,   300,   124,    94,    38,
      62,    60,    43,    45,    47,    42,    37,    33,   126,   301,
     302,   303,   304,    46,    91,    93,    40,    41,   305,    44,
     123,   125,    59
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CParser::yyr1_[] =
  {
         0,    73,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    82,    82,    83,    84,    84,    84,
      85,    85,    86,    86,    87,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      93,    93,    94,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     3,     1,     3,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     0,     2,     2,     1,     3,     4,
       5,     4,     1,     3,     2,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       0,     2,     1,     2,     5,     7,     5,     7,     9,     9,
       2,     2,     3,     2,     1,     2,     1,     2,     2
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CParser::yytname_[] =
  {
    "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "IMMEDIATE_INTEGER", "CHAR_LITERAL", "INC_OP", "DEC_OP", "PTR_OP",
  "SHIFT_LEFT_OP", "SHIFT_RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "AND_OP", "OR_OP", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN",
  "AND_ASSIGN", "INCLUSIVE_OR_ASSIGN", "EXCLUSIVE_OR_ASSIGN", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "CONTINUE",
  "BREAK", "RETURN", "CHAR", "INT", "FLOAT", "CONST", "VOID", "'='",
  "OR_ASSIGN", "XOR_ASSIGN", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'",
  "'-'", "'/'", "'*'", "'%'", "'!'", "'~'", "UADD", "UMINUS",
  "DEREFERENCE", "REFERENCE", "'.'", "'['", "']'", "'('", "')'",
  "LOWER_THAN_ELSE", "','", "'{'", "'}'", "';'", "$accept", "program",
  "expression", "argument_expression_list", "declaration_specifiers",
  "variable_declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "pointer", "declarator", "direct_declarator",
  "function_declarator", "parameter_list", "parameter_declaration",
  "identifier", "initializer", "initializer_list", "statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "if_statement", "while_statement",
  "for_statement", "jump_statement", "return_statement",
  "translation_unit", "declaration", "function_declaration", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CParser::rhs_number_type
  CParser::yyrhs_[] =
  {
        74,     0,    -1,   101,    -1,    88,    -1,     5,    -1,     4,
      -1,     6,    -1,    66,    75,    67,    -1,    75,    52,    75,
      -1,    75,    53,    75,    -1,    75,    55,    75,    -1,    75,
      54,    75,    -1,    75,    56,    75,    -1,    75,    48,    75,
      -1,    75,    47,    75,    -1,    75,    49,    75,    -1,    75,
      10,    75,    -1,    75,    11,    75,    -1,    75,    50,    75,
      -1,    75,    51,    75,    -1,    75,    14,    75,    -1,    75,
      12,    75,    -1,    75,    13,    75,    -1,    75,    15,    75,
      -1,    75,    44,    75,    -1,    75,    18,    75,    -1,    75,
      19,    75,    -1,    75,    20,    75,    -1,    75,    21,    75,
      -1,    75,    22,    75,    -1,    75,    25,    75,    -1,    75,
      27,    75,    -1,    75,    26,    75,    -1,    75,    23,    75,
      -1,    75,    24,    75,    -1,    75,    16,    75,    -1,    75,
      17,    75,    -1,    75,    64,    75,    65,    -1,    75,    63,
      75,    -1,    75,     9,    75,    -1,    75,     7,    -1,    75,
       8,    -1,     7,    75,    -1,     8,    75,    -1,    49,    75,
      -1,    55,    75,    -1,    52,    75,    -1,    53,    75,    -1,
      58,    75,    -1,    57,    75,    -1,    88,    66,    76,    67,
      -1,    88,    66,    67,    -1,    75,    -1,    76,    69,    75,
      -1,    81,    -1,    77,    79,    -1,    80,    -1,    79,    69,
      80,    -1,    83,    -1,    83,    44,    89,    -1,    43,    -1,
      39,    -1,    40,    -1,    41,    -1,    -1,    55,    82,    -1,
      82,    84,    -1,    88,    -1,    84,    64,    65,    -1,    84,
      64,    75,    65,    -1,    77,    83,    66,    86,    67,    -1,
      77,    83,    66,    67,    -1,    87,    -1,    86,    69,    87,
      -1,    77,    83,    -1,     3,    -1,    75,    -1,    70,    90,
      71,    -1,    89,    -1,    90,    69,    89,    -1,    72,    -1,
      92,    -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,    78,    72,    -1,    70,    93,    71,
      -1,    -1,    93,    94,    -1,    91,    -1,    75,    72,    -1,
      30,    66,    75,    67,    91,    -1,    30,    66,    75,    67,
      91,    31,    91,    -1,    33,    66,    75,    67,    91,    -1,
      34,    91,    33,    66,    75,    67,    72,    -1,    35,    66,
      75,    72,    75,    72,    75,    67,    91,    -1,    35,    66,
      78,    72,    75,    72,    75,    67,    91,    -1,    36,    72,
      -1,    37,    72,    -1,    38,    75,    72,    -1,    38,    72,
      -1,   102,    -1,   101,   102,    -1,   103,    -1,    78,    72,
      -1,    85,    92,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  CParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    11,    13,    17,    21,
      25,    29,    33,    37,    41,    45,    49,    53,    57,    61,
      65,    69,    73,    77,    81,    85,    89,    93,    97,   101,
     105,   109,   113,   117,   121,   125,   129,   133,   138,   142,
     146,   149,   152,   155,   158,   161,   164,   167,   170,   173,
     176,   181,   185,   187,   191,   193,   196,   198,   202,   204,
     208,   210,   212,   214,   216,   217,   220,   223,   225,   229,
     234,   240,   245,   247,   251,   254,   256,   258,   262,   264,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   287,
     291,   292,   295,   297,   300,   306,   314,   320,   328,   338,
     348,   351,   354,   358,   361,   363,   366,   368,   371
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CParser::yyrline_[] =
  {
         0,   139,   139,   143,   144,   148,   181,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   259,   260,   273,   289,   298,   302,   317,   318,
     325,   326,   327,   328,   332,   333,   337,   346,   350,   354,
     367,   373,   381,   385,   392,   399,   403,   404,   411,   415,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   433,
     439,   443,   450,   454,   460,   463,   469,   472,   479,   482,
     489,   492,   498,   501,   511,   515,   521,   524,   530
  };

  // Print the state stack on the debug stream.
  void
  CParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  CParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  CParser::token_number_type
  CParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    56,    49,     2,
      66,    67,    55,    52,    69,    53,    63,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    72,
      51,    44,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    47,    71,    58,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45,
      46,    59,    60,    61,    62,    68
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CParser::yyeof_ = 0;
  const int CParser::yylast_ = 1508;
  const int CParser::yynnts_ = 31;
  const int CParser::yyempty_ = -2;
  const int CParser::yyfinal_ = 13;
  const int CParser::yyterror_ = 1;
  const int CParser::yyerrcode_ = 256;
  const int CParser::yyntokens_ = 73;

  const unsigned int CParser::yyuser_token_number_max_ = 305;
  const CParser::token_number_type CParser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 2046 "CParser.cpp"
/* Line 1142 of lalr1.cc  */
#line 535 "CParser.y"


namespace yy
{
void CParser::error(location const& loc, const std::string& s) {
	std::cerr << "error at " << loc << ": " << s << std::endl;
}
}