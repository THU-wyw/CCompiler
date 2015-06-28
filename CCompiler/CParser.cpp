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
#line 129 "CParser.y"


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
#line 137 "CParser.y"
    { (yyval.program) = (yysemantic_stack_[(1) - (1)].program); driver.set_program((yysemantic_stack_[(1) - (1)].program)); }
    break;

  case 3:
/* Line 670 of lalr1.cc  */
#line 141 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(1) - (1)].identifier); }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 142 "CParser.y"
    { 
		(yyval.expression) = new ImmediateInteger(atol((yysemantic_stack_[(1) - (1)].str)->c_str())); 
		delete (yysemantic_stack_[(1) - (1)].str);
	}
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 146 "CParser.y"
    {
		(yyval.expression) = new StringLiteral(*(yysemantic_stack_[(1) - (1)].str));
		delete (yysemantic_stack_[(1) - (1)].str);
	}
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 150 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(3) - (2)].expression); }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 151 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::ADD); }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 152 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SUB); }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 153 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::MUL); }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 154 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::DIV); }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 155 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::MOD); }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 156 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::XOR_BIT); }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 157 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::OR_BIT); }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 158 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::AND_BIT); }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 159 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_LEFT); }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 160 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::SHIFT_RIGHT); }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 161 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::GREATER); }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 162 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::LESS); }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 163 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::EQUAL); }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 164 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::LESS_EQUAL); }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 165 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::GREATER_EQUAL); }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 166 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::NOT_EQUAL); }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 167 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::ASSIGN); }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 168 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::ADD_ASSIGN); }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 169 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SUB_ASSIGN); }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 170 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::MUL_ASSIGN); }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 171 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::DIV_ASSIGN); }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 172 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::MOD_ASSIGN); }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 173 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::AND_ASSIGN); }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 174 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::EXCLUSIVE_OR_ASSIGN); }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 175 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::INCLUSIVE_OR_ASSIGN); }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 176 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_LEFT_ASSIGN); }
    break;

  case 33:
/* Line 670 of lalr1.cc  */
#line 177 "CParser.y"
    { (yyval.expression) = new AssignmentExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), AssignmentExpression::Operator::SHIFT_RIGHT_ASSIGN); }
    break;

  case 34:
/* Line 670 of lalr1.cc  */
#line 178 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::AND); }
    break;

  case 35:
/* Line 670 of lalr1.cc  */
#line 179 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::OR); }
    break;

  case 36:
/* Line 670 of lalr1.cc  */
#line 180 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(4) - (1)].expression), (yysemantic_stack_[(4) - (3)].expression), BinaryExpression::Operator::INDEX); }
    break;

  case 37:
/* Line 670 of lalr1.cc  */
#line 181 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::DOT); }
    break;

  case 38:
/* Line 670 of lalr1.cc  */
#line 182 "CParser.y"
    { (yyval.expression) = new BinaryExpression((yysemantic_stack_[(3) - (1)].expression), (yysemantic_stack_[(3) - (3)].expression), BinaryExpression::Operator::POINTER); }
    break;

  case 39:
/* Line 670 of lalr1.cc  */
#line 183 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (1)].expression), UnaryExpression::Operator::INC_AFTER); }
    break;

  case 40:
/* Line 670 of lalr1.cc  */
#line 184 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (1)].expression), UnaryExpression::Operator::DEC_AFTER); }
    break;

  case 41:
/* Line 670 of lalr1.cc  */
#line 185 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::INC_PRE); }
    break;

  case 42:
/* Line 670 of lalr1.cc  */
#line 186 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::DEC_PRE); }
    break;

  case 43:
/* Line 670 of lalr1.cc  */
#line 187 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::REFERENCE); }
    break;

  case 44:
/* Line 670 of lalr1.cc  */
#line 188 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::DEREFERENCE); }
    break;

  case 45:
/* Line 670 of lalr1.cc  */
#line 189 "CParser.y"
    { (yyval.expression) = (yysemantic_stack_[(2) - (2)].expression); }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 190 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::MINUS); }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 191 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::NOT_BIT); }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 192 "CParser.y"
    { (yyval.expression) = new UnaryExpression((yysemantic_stack_[(2) - (2)].expression), UnaryExpression::Operator::NOT); }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 193 "CParser.y"
    { (yyval.expression) = new FunctionCall((yysemantic_stack_[(4) - (1)].identifier), *((yysemantic_stack_[(4) - (3)].expression_list))); }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 194 "CParser.y"
    { (yyval.expression) = new FunctionCall((yysemantic_stack_[(3) - (1)].identifier), std::vector<Expression *>()); }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 198 "CParser.y"
    { (yyval.expression_list) = new std::vector<Expression*>(); (yyval.expression_list)->push_back((yysemantic_stack_[(1) - (1)].expression)); }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 199 "CParser.y"
    { (yyval.expression_list)->push_back((yysemantic_stack_[(3) - (3)].expression)); }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 228 "CParser.y"
    {
		for (auto iterator = (yysemantic_stack_[(2) - (2)].variable_declaration_list)->begin(); iterator != (yysemantic_stack_[(2) - (2)].variable_declaration_list)->end(); iterator++) {
			(*iterator)->set_basic_type((yysemantic_stack_[(2) - (1)].vt_t));
		}
		(yyval.variable_declaration) = *((yysemantic_stack_[(2) - (2)].variable_declaration_list)->begin());
	}
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 237 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yysemantic_stack_[(1) - (1)].variable_declaration));
	}
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 241 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration_list)->push_back((yysemantic_stack_[(3) - (3)].variable_declaration));
		(yyval.variable_declaration_list) = (yysemantic_stack_[(3) - (1)].variable_declaration_list);
	}
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 257 "CParser.y"
    {
		(yyval.variable_declaration) = (yysemantic_stack_[(3) - (1)].variable_declaration);
		(yyval.variable_declaration)->set_initializer((yysemantic_stack_[(3) - (3)].expression));
	}
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 264 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::VOID; }
    break;

  case 60:
/* Line 670 of lalr1.cc  */
#line 265 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::CHARACTER; }
    break;

  case 61:
/* Line 670 of lalr1.cc  */
#line 266 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::INTEGER; }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 267 "CParser.y"
    { (yyval.vt_t) = Type::BasicType::FLOAT; }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 271 "CParser.y"
    { (yyval.number) = 0; }
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 272 "CParser.y"
    { (yyval.number) = (yysemantic_stack_[(2) - (2)].number) + 1; }
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 276 "CParser.y"
    {
		for (int i = 0; i < (yysemantic_stack_[(2) - (1)].number); i++) {
			(yysemantic_stack_[(2) - (2)].variable_declaration)->AddPointerSpecifier(); 
		}
		(yyval.variable_declaration) = (yysemantic_stack_[(2) - (2)].variable_declaration);
	}
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 285 "CParser.y"
    {
		(yyval.variable_declaration) = new VariableDeclaration();
		(yyval.variable_declaration)->set_identifier((yysemantic_stack_[(1) - (1)].identifier));
	}
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 289 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration)->AddArraySpecifier(nullptr);
		(yyval.variable_declaration) = (yysemantic_stack_[(3) - (1)].variable_declaration);
	}
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 293 "CParser.y"
    {
		(yysemantic_stack_[(4) - (1)].variable_declaration)->AddArraySpecifier((yysemantic_stack_[(4) - (3)].expression)); 
		(yyval.variable_declaration) = (yysemantic_stack_[(4) - (1)].variable_declaration);
	}
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 306 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration(*((yysemantic_stack_[(5) - (4)].variable_declaration_list)));
		(yysemantic_stack_[(5) - (2)].variable_declaration)->SetAsFunctionDeclaration(*(yyval.function_declaration));
		delete (yysemantic_stack_[(5) - (4)].variable_declaration_list);
	}
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 311 "CParser.y"
    {
		(yyval.function_declaration) = new FunctionDeclaration(std::vector<VariableDeclaration*>());
		(yysemantic_stack_[(4) - (2)].variable_declaration)->SetAsFunctionDeclaration(*(yyval.function_declaration));
	}
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 318 "CParser.y"
    {
		(yyval.variable_declaration_list) = new std::vector<VariableDeclaration*>();
		(yyval.variable_declaration_list)->push_back((yysemantic_stack_[(1) - (1)].variable_declaration));
	}
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 322 "CParser.y"
    {
		(yysemantic_stack_[(3) - (1)].variable_declaration_list)->push_back((yysemantic_stack_[(3) - (3)].variable_declaration));
		(yyval.variable_declaration_list) = (yysemantic_stack_[(3) - (1)].variable_declaration_list);
	}
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 329 "CParser.y"
    {
		(yysemantic_stack_[(2) - (2)].variable_declaration)->set_basic_type((yysemantic_stack_[(2) - (1)].vt_t));
		(yyval.variable_declaration) = (yysemantic_stack_[(2) - (2)].variable_declaration);
	}
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 336 "CParser.y"
    { (yyval.identifier) = new Identifier(*(yysemantic_stack_[(1) - (1)].str)); }
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 348 "CParser.y"
    { (yyval.statement) = new ExpressionStatement(nullptr); }
    break;

  case 84:
/* Line 670 of lalr1.cc  */
#line 356 "CParser.y"
    { (yyval.statement) = new DeclarationStatement((yysemantic_stack_[(2) - (1)].variable_declaration)); }
    break;

  case 85:
/* Line 670 of lalr1.cc  */
#line 360 "CParser.y"
    {
		(yyval.statement) = (yysemantic_stack_[(3) - (2)].statement);
	}
    break;

  case 86:
/* Line 670 of lalr1.cc  */
#line 366 "CParser.y"
    {
		(yyval.statement) = new StatementsBlock();
		//((StatementsBlock *)$$)->PushStatement($1);
	}
    break;

  case 87:
/* Line 670 of lalr1.cc  */
#line 370 "CParser.y"
    {
		((StatementsBlock *)(yysemantic_stack_[(2) - (1)].statement))->PushStatement((yysemantic_stack_[(2) - (2)].statement));
		(yyval.statement) = (yysemantic_stack_[(2) - (1)].statement);
	}
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 381 "CParser.y"
    {
		(yyval.statement) = new ExpressionStatement((yysemantic_stack_[(2) - (1)].expression));
	}
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 387 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yysemantic_stack_[(5) - (3)].expression), (yysemantic_stack_[(5) - (5)].statement));
	}
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 390 "CParser.y"
    {
		(yyval.statement) = new IfStatement((yysemantic_stack_[(7) - (3)].expression), (yysemantic_stack_[(7) - (5)].statement), (yysemantic_stack_[(7) - (7)].statement));
	}
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 396 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yysemantic_stack_[(5) - (3)].expression), (yysemantic_stack_[(5) - (5)].statement));
	}
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 399 "CParser.y"
    {
		(yyval.statement) = new WhileStatement ((yysemantic_stack_[(7) - (5)].expression), (yysemantic_stack_[(7) - (2)].statement), true);
	}
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 406 "CParser.y"
    {
		(yyval.statement) = new ForStatement((yysemantic_stack_[(9) - (3)].expression), (yysemantic_stack_[(9) - (5)].expression), (yysemantic_stack_[(9) - (7)].expression), (yysemantic_stack_[(9) - (9)].statement));
	}
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 409 "CParser.y"
    {
		(yyval.statement) = new ForStatement((yysemantic_stack_[(9) - (3)].variable_declaration), (yysemantic_stack_[(9) - (5)].expression), (yysemantic_stack_[(9) - (7)].expression), (yysemantic_stack_[(9) - (9)].statement));
	}
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 416 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::CONTINUE);
	}
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 419 "CParser.y"
    {
		(yyval.statement) = new JumpStatement(JumpStatement::BREAK);
	}
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 425 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement((yysemantic_stack_[(3) - (2)].expression));
	}
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 428 "CParser.y"
    {
		(yyval.statement) = new ReturnStatement(nullptr);
	}
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 438 "CParser.y"
    {
		(yyval.program) = new Program();
		(yyval.program)->PushDeclaration((yysemantic_stack_[(1) - (1)].declaration));
	}
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 442 "CParser.y"
    {
		(yyval.program)->PushDeclaration((yysemantic_stack_[(2) - (2)].declaration));
	}
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 448 "CParser.y"
    {
		(yyval.declaration) = (yysemantic_stack_[(1) - (1)].function_declaration);
	}
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 451 "CParser.y"
    {
		(yyval.declaration) = (yysemantic_stack_[(1) - (1)].variable_declaration);
	}
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 457 "CParser.y"
    {
		(yysemantic_stack_[(2) - (1)].function_declaration)->set_body((yysemantic_stack_[(2) - (2)].statement));
		(yyval.function_declaration) = (yysemantic_stack_[(2) - (1)].function_declaration);
	}
    break;


/* Line 670 of lalr1.cc  */
#line 1074 "CParser.cpp"
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
  const signed char CParser::yypact_ninf_ = -63;
  const short int
  CParser::yypact_[] =
  {
         0,   -63,   -63,   -63,   -63,    26,   -25,   -63,   -63,   -43,
       0,   -63,   -63,   -63,   -25,   -37,   -63,    30,   -40,   -63,
     -63,   -63,   -63,   -25,   -63,   -31,   -63,   621,   -19,   137,
     -63,    -9,   592,   -63,   -63,   621,   621,   621,   621,   621,
     621,   621,   621,   621,  1165,   -24,   -63,   -63,   -25,   -62,
     -63,   -22,   -20,   192,   -17,   -13,   -12,    48,   -63,   -63,
     257,   -25,    24,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,  1047,    29,    29,    29,    29,    29,    29,
      29,    29,   681,   -63,   -63,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   537,   -63,   -63,
       0,   621,   621,    17,   566,   -63,   -63,   -63,   321,   -63,
     -63,   -63,   -63,   -63,  1371,  1371,   657,   657,  1409,  1409,
    1262,  1244,  1186,  1186,  1186,  1186,  1186,  1186,  1186,  1186,
    1186,  1186,  1186,  1320,  1336,  1351,   657,   657,   150,   150,
     100,   100,   100,   -63,  1106,   -63,  1165,   -44,   -63,   742,
     803,   -15,   385,    32,   -63,   -63,   -63,   621,   192,   192,
     621,   621,   621,  1165,    68,   -63,   864,   449,   513,   192,
      34,   621,   621,   -63,   -63,   925,   986,   192,   192,   -63,
     -63
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  CParser::yydefact_[] =
  {
         0,    60,    61,    62,    59,     0,    63,   103,    53,     0,
       2,   100,   102,     1,    63,    54,    55,     0,    57,    86,
     104,   101,    64,    63,    74,    65,    66,     0,     0,     0,
      56,    57,     0,     5,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     3,    58,    70,    63,     0,
      71,     0,     0,     0,     0,     0,     0,     0,    76,    85,
       0,    63,     0,    88,    77,    87,    78,    79,    80,    81,
      82,    83,    67,     0,    41,    42,    43,    45,    46,    44,
      48,    47,     0,    39,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    69,
       0,     0,     0,     0,     0,    96,    97,    99,     0,    89,
      84,    68,     6,    38,    15,    16,    20,    21,    19,    22,
      34,    35,    24,    25,    26,    27,    28,    32,    33,    29,
      31,    30,    23,    13,    12,    14,    17,    18,     7,     8,
      10,     9,    11,    37,     0,    50,    51,     0,    72,     0,
       0,     0,     0,     0,    98,    36,    49,     0,     0,     0,
       0,     0,     0,    52,    90,    92,     0,     0,     0,     0,
       0,     0,     0,    91,    93,     0,     0,     0,     0,    94,
      95
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  CParser::yypgoto_[] =
  {
       -63,   -63,   -27,   -63,    18,     7,   -63,    86,   -63,    96,
      -4,   -63,   -63,   -63,    -8,    94,   -63,   -52,   105,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   106,   -63
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  CParser::yydefgoto_[] =
  {
        -1,     5,    60,   167,    61,    62,    15,    16,     8,    17,
      31,    25,     9,    49,    50,    45,    46,    63,    64,    29,
      65,    66,    67,    68,    69,    70,    71,    10,    11,    12
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char CParser::yytable_ninf_ = -1;
  const short int
  CParser::yytable_[] =
  {
        44,   123,    18,    27,   119,    73,   120,     7,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     7,     6,     1,
       2,     3,   176,     4,   177,    28,    13,    19,     6,    14,
     128,    23,    32,    24,    27,    -1,    -1,    85,     1,     2,
       3,   117,     4,   121,   118,   122,    48,    47,   124,   171,
     180,    24,    33,    34,    35,    36,   125,   126,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     166,   115,   116,   130,   169,   170,    37,   172,   189,    38,
      39,   182,    40,   194,    41,    42,    83,    84,    85,    30,
      22,    26,   168,    43,    20,     0,    21,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   184,   185,     0,     0,
       0,   173,     0,     0,     0,     0,     0,   193,    48,     0,
      24,    33,    34,    35,    36,   199,   200,     0,     0,     0,
     183,     0,     0,   186,   187,   188,    83,    84,    85,     0,
       0,     0,   115,   116,   195,   196,    51,     0,     0,    52,
      53,    54,    55,    56,    57,     1,     2,     3,     0,     4,
       0,     0,     0,     0,     0,    37,     0,     0,    38,    39,
       0,    40,     0,    41,    42,    24,    33,    34,    35,    36,
       0,     0,    43,   112,   113,   114,    58,    19,    59,     0,
       0,     0,   115,   116,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,    52,    53,    54,    55,    56,    57,
       1,     2,     3,     0,     4,     0,     0,     0,     0,     0,
      37,     0,     0,    38,    39,     0,    40,     0,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,    58,    19,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   115,
     116,     0,     0,     0,     0,     0,   129,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,     0,     0,     0,
     174,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,   115,   116,     0,
       0,     0,     0,     0,   181,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,   115,   116,     0,     0,     0,     0,     0,   191,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      24,    33,    34,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    24,
      33,    34,    35,    36,     0,   115,   116,     0,     0,     0,
       0,     0,   192,     0,     0,    37,     0,     0,    38,    39,
       0,    40,     0,    41,    42,    24,    33,    34,    35,    36,
       0,     0,    43,   165,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,    37,     0,     0,    38,    39,     0,
      40,     0,    41,    42,    24,    33,    34,    35,    36,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,    38,    39,     0,    40,     0,    41,    42,
       0,     0,     0,     0,     0,     0,    72,    43,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,     0,    37,
       0,     0,    38,    39,     0,    40,     0,    41,    42,     0,
       0,     0,     0,     0,     0,     0,    43,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   115,
     116,     0,     0,     0,   104,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,   132,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,     0,   115,   116,     0,     0,   178,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,   115,   116,     0,     0,   179,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,   115,   116,     0,     0,
     190,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,   115,   116,     0,
       0,   197,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   115,   116,
       0,     0,   198,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   115,
     116,   131,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   115,   116,
     175,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,     0,     0,     0,     0,     0,   104,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,   115,   116,     0,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   115,   116,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,   115,   116,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,     0,   115,   116,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,    83,    84,    85,
       0,     0,   115,   116,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,   115,   116,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,   115,   116,    83,    84,    85,    86,    87,
      88,    89,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,   115,   116
  };

  /* YYCHECK.  */
  const short int
  CParser::yycheck_[] =
  {
        27,    53,     6,    43,    66,    32,    68,     0,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    10,     0,    38,
      39,    40,    66,    42,    68,    65,     0,    70,    10,    54,
      57,    68,    63,     3,    43,     6,     7,     8,    38,    39,
      40,    65,    42,    65,    48,    65,    28,    66,    65,    32,
      65,     3,     4,     5,     6,     7,    69,    69,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    62,    63,    69,   121,   122,    48,   124,    30,    51,
      52,    69,    54,    69,    56,    57,     6,     7,     8,    23,
      14,    17,   120,    65,     9,    -1,    10,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   178,   179,    -1,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,   189,   120,    -1,
       3,     4,     5,     6,     7,   197,   198,    -1,    -1,    -1,
     177,    -1,    -1,   180,   181,   182,     6,     7,     8,    -1,
      -1,    -1,    62,    63,   191,   192,    29,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    54,    -1,    56,    57,     3,     4,     5,     6,     7,
      -1,    -1,    65,    53,    54,    55,    69,    70,    71,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,
      -1,    69,    70,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      69,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    69,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,     3,
       4,     5,     6,     7,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    48,    -1,    -1,    51,    52,
      -1,    54,    -1,    56,    57,     3,     4,     5,     6,     7,
      -1,    -1,    65,    66,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    51,    52,    -1,
      54,    -1,    56,    57,     3,     4,     5,     6,     7,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    51,    52,    -1,    54,    -1,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    -1,    48,
      -1,    -1,    51,    52,    -1,    54,    -1,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    66,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,
      66,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,     6,     7,     8,
      -1,    -1,    62,    63,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,     6,     7,     8,     9,    10,
      11,    12,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    63
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CParser::yystos_[] =
  {
         0,    38,    39,    40,    42,    73,    76,    77,    80,    84,
      99,   100,   101,     0,    54,    78,    79,    81,    82,    70,
      90,   100,    81,    68,     3,    83,    87,    43,    65,    91,
      79,    82,    63,     4,     5,     6,     7,    48,    51,    52,
      54,    56,    57,    65,    74,    87,    88,    66,    76,    85,
      86,    29,    32,    33,    34,    35,    36,    37,    69,    71,
      74,    76,    77,    89,    90,    92,    93,    94,    95,    96,
      97,    98,    64,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    43,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    62,    63,    65,    82,    66,
      68,    65,    65,    89,    65,    69,    69,    69,    74,    69,
      69,    64,    66,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    66,    74,    75,    86,    74,
      74,    32,    74,    77,    69,    64,    66,    68,    66,    66,
      65,    69,    69,    74,    89,    89,    74,    74,    74,    30,
      66,    69,    69,    89,    69,    74,    74,    66,    66,    89,
      89
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
     295,   296,   297,    61,   298,   299,   124,    94,    38,    62,
      60,    43,    45,    47,    42,    37,    33,   126,   300,   301,
     302,   303,    46,    91,    93,    40,    41,   304,    44,    59,
     123,   125
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CParser::yyr1_[] =
  {
         0,    72,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    87,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    91,    91,    92,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   101
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CParser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       3,     1,     3,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     0,     2,     2,     1,     3,     4,     5,
       4,     1,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     0,     2,     1,     2,
       5,     7,     5,     7,     9,     9,     2,     2,     3,     2,
       1,     2,     1,     1,     2
  };

#if YYDEBUG
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CParser::yytname_[] =
  {
    "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "IMMEDIATE_INTEGER", "INC_OP", "DEC_OP", "PTR_OP", "SHIFT_LEFT_OP",
  "SHIFT_RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT_ASSIGN", "AND_ASSIGN",
  "INCLUSIVE_OR_ASSIGN", "EXCLUSIVE_OR_ASSIGN", "CASE", "DEFAULT", "IF",
  "ELSE", "SWITCH", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN",
  "CHAR", "INT", "FLOAT", "CONST", "VOID", "'='", "OR_ASSIGN",
  "XOR_ASSIGN", "'|'", "'^'", "'&'", "'>'", "'<'", "'+'", "'-'", "'/'",
  "'*'", "'%'", "'!'", "'~'", "UADD", "UMINUS", "DEREFERENCE", "REFERENCE",
  "'.'", "'['", "']'", "'('", "')'", "LOWER_THAN_ELSE", "','", "';'",
  "'{'", "'}'", "$accept", "program", "expression",
  "argument_expression_list", "declaration_specifiers",
  "variable_declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "pointer", "declarator", "direct_declarator",
  "function_declarator", "parameter_list", "parameter_declaration",
  "identifier", "initializer", "statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement", "if_statement",
  "while_statement", "for_statement", "jump_statement", "return_statement",
  "translation_unit", "declaration", "function_declaration", YY_NULL
  };


  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CParser::rhs_number_type
  CParser::yyrhs_[] =
  {
        73,     0,    -1,    99,    -1,    87,    -1,     5,    -1,     4,
      -1,    65,    74,    66,    -1,    74,    51,    74,    -1,    74,
      52,    74,    -1,    74,    54,    74,    -1,    74,    53,    74,
      -1,    74,    55,    74,    -1,    74,    47,    74,    -1,    74,
      46,    74,    -1,    74,    48,    74,    -1,    74,     9,    74,
      -1,    74,    10,    74,    -1,    74,    49,    74,    -1,    74,
      50,    74,    -1,    74,    13,    74,    -1,    74,    11,    74,
      -1,    74,    12,    74,    -1,    74,    14,    74,    -1,    74,
      43,    74,    -1,    74,    17,    74,    -1,    74,    18,    74,
      -1,    74,    19,    74,    -1,    74,    20,    74,    -1,    74,
      21,    74,    -1,    74,    24,    74,    -1,    74,    26,    74,
      -1,    74,    25,    74,    -1,    74,    22,    74,    -1,    74,
      23,    74,    -1,    74,    15,    74,    -1,    74,    16,    74,
      -1,    74,    63,    74,    64,    -1,    74,    62,    74,    -1,
      74,     8,    74,    -1,    74,     6,    -1,    74,     7,    -1,
       6,    74,    -1,     7,    74,    -1,    48,    74,    -1,    54,
      74,    -1,    51,    74,    -1,    52,    74,    -1,    57,    74,
      -1,    56,    74,    -1,    87,    65,    75,    66,    -1,    87,
      65,    66,    -1,    74,    -1,    75,    68,    74,    -1,    80,
      -1,    76,    78,    -1,    79,    -1,    78,    68,    79,    -1,
      82,    -1,    82,    43,    88,    -1,    42,    -1,    38,    -1,
      39,    -1,    40,    -1,    -1,    54,    81,    -1,    81,    83,
      -1,    87,    -1,    83,    63,    64,    -1,    83,    63,    74,
      64,    -1,    76,    82,    65,    85,    66,    -1,    76,    82,
      65,    66,    -1,    86,    -1,    85,    68,    86,    -1,    76,
      82,    -1,     3,    -1,    74,    -1,    69,    -1,    90,    -1,
      93,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,    77,    69,    -1,    70,    91,    71,    -1,    -1,
      91,    92,    -1,    89,    -1,    74,    69,    -1,    29,    65,
      74,    66,    89,    -1,    29,    65,    74,    66,    89,    30,
      89,    -1,    32,    65,    74,    66,    89,    -1,    33,    89,
      32,    65,    74,    66,    69,    -1,    34,    65,    74,    69,
      74,    69,    74,    66,    89,    -1,    34,    65,    77,    69,
      74,    69,    74,    66,    89,    -1,    35,    69,    -1,    36,
      69,    -1,    37,    74,    69,    -1,    37,    69,    -1,   100,
      -1,    99,   100,    -1,   101,    -1,    77,    -1,    84,    90,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  CParser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    11,    15,    19,    23,
      27,    31,    35,    39,    43,    47,    51,    55,    59,    63,
      67,    71,    75,    79,    83,    87,    91,    95,    99,   103,
     107,   111,   115,   119,   123,   127,   131,   136,   140,   144,
     147,   150,   153,   156,   159,   162,   165,   168,   171,   174,
     179,   183,   185,   189,   191,   194,   196,   200,   202,   206,
     208,   210,   212,   214,   215,   218,   221,   223,   227,   232,
     238,   243,   245,   249,   252,   254,   256,   258,   260,   262,
     264,   266,   268,   270,   272,   275,   279,   280,   283,   285,
     288,   294,   302,   308,   316,   326,   336,   339,   342,   346,
     349,   351,   354,   356,   358
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CParser::yyrline_[] =
  {
         0,   137,   137,   141,   142,   146,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   198,   199,   212,   228,   237,   241,   256,   257,   264,
     265,   266,   267,   271,   272,   276,   285,   289,   293,   306,
     311,   318,   322,   329,   336,   340,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   360,   366,   370,   377,   381,
     387,   390,   396,   399,   406,   409,   416,   419,   425,   428,
     438,   442,   448,   451,   457
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
       2,     2,     2,    56,     2,     2,     2,    55,    48,     2,
      65,    66,    54,    51,    68,    52,    62,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    69,
      50,    43,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    46,    71,    57,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      58,    59,    60,    61,    67
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CParser::yyeof_ = 0;
  const int CParser::yylast_ = 1472;
  const int CParser::yynnts_ = 30;
  const int CParser::yyempty_ = -2;
  const int CParser::yyfinal_ = 13;
  const int CParser::yyterror_ = 1;
  const int CParser::yyerrcode_ = 256;
  const int CParser::yyntokens_ = 72;

  const unsigned int CParser::yyuser_token_number_max_ = 304;
  const CParser::token_number_type CParser::yyundef_token_ = 2;


} // yy
/* Line 1141 of lalr1.cc  */
#line 1947 "CParser.cpp"
/* Line 1142 of lalr1.cc  */
#line 462 "CParser.y"


namespace yy
{
void CParser::error(location const& loc, const std::string& s) {
	std::cerr << "error at " << loc << ": " << s << std::endl;
}
}