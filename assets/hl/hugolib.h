!----------------------------------------------------------------------------
!
!           Hugo Library v3.1.03.2 by Kent Tessman (c) 1995-2006
!                     for use with the Hugo Compiler
!
!----------------------------------------------------------------------------

#ifclear _HUGOLIB_H
#set _HUGOLIB_H

constant BANNER "Hugo v3.1 / Library 31032"
constant HUGO_VERSION   "v3.1"

!----------------------------------------------------------------------------
! RESERVED PROPERTIES:
!----------------------------------------------------------------------------

!\ The first 6 are pre-defined by the compiler:

property name                           ! property 0:  basic object name
property before $additive $complex      ! pre-verb routines
property after  $additive $complex      ! post-verb routines
property noun                           ! noun(s) for referring to object
property adjective                      ! adjective(s) describing object
property article                        ! "a", "an", "some", etc.
\!

property nouns alias noun               !
property adjectives alias adjective     !
property preposition                    ! "in", "inside", "outside of", etc.
property prep alias preposition         !
property pronoun "it"                   ! "he", "him", "his", "himself"
property pronouns alias pronoun         !   (or equivalent)
property react_before                   ! to allow reaction by an object that
property react_after                    !   is not directly involved
property short_desc                     ! basic "X is here" description
property initial_desc                   ! same as above, before obj. is moved
property long_desc                      ! detailed description
property found_in                       ! in case of multiple parents
property type                           ! to identify the type of object
property size 10                        ! for holding/inventory purposes
property capacity                       !  "          "            "
property holding                        !  "          "            "
property reach                          ! for limiting accessible objects
property list_contents                  ! to override normal listing routine
property in_scope                       ! actor(s) which can access an object
property parse_rank                     ! for matching similarly named objects
property exclude_from_all               ! i.e., exclude from multi-obj. verbs
property door_to                        ! for handling "Enter <object>"

! The following are used only for room objects:
property n_to                           !
property ne_to                          !
property e_to                           !
property se_to                          !
property s_to                           ! If the player can move from one
property sw_to                          ! room to another in direction X,
property w_to                           ! X_to holds the object number of the
property nw_to                          ! second room.
property u_to                           !
property d_to                           !
property in_to                          !
property out_to                         !
property cant_go                        ! message if a move is invalid
property extra_scenery                  ! unimportant words/objects in desc.
property each_turn                      ! a routine called each turn

! The following are used only for non-room objects:
property key_object alias ne_to         ! if lockable, what is the key?
property when_open alias e_to           ! desc. for openable objects
property when_closed alias se_to        !   "    "     "        "
property ignore_response alias s_to     ! for unfriendly characters
property order_response alias sw_to     ! for giving orders to characters
property contains_desc alias w_to       ! instead of "X contains...", etc.
property inv_desc alias nw_to           ! for inventory listing only
property desc_detail alias u_to         ! parenthetical detail (ObjectIs)

property misc                           ! miscellaneous use


!----------------------------------------------------------------------------
! RESERVED ATTRIBUTES:
!----------------------------------------------------------------------------

attribute known                         ! set once an object is known about
attribute moved                         !  "  once an object is moved
attribute visited alias moved           !  "  once a room is visited
attribute static                        !  "  when object cannot be taken
attribute plural                        !  "  for plural objects
attribute living                        !  "  if object is a character
attribute female                        !  "  if character is female
attribute openable                      !  "  if object can be opened
attribute open                          !  "  if object is open
attribute lockable                      !  "  if object can be locked
attribute locked                        !  "  if object is locked
attribute unfriendly                    ! for characters
attribute light                         ! set if an object is/provides light
attribute readable                      !  "  if object can be read
attribute switchable                    !  "  if object can be turned on/off
attribute switchedon                    !  "  if object is on
attribute active alias switchedon       ! generally for fuses/daemons
attribute clothing                      ! set if object can be worn
attribute worn                          !  "  if object is being worn
attribute mobile alias worn             !  "  if object may be moved around
attribute enterable                     !  "  if object may be entered
attribute container                     !  "  if things can be placed IN obj.
attribute platform                      !  "  if things can be placed ON obj.
                                        !     ("container" and "platform" are
                                        !      mutually exclusive)
attribute hidden                        !  "  if object isn't listed
attribute quiet                         !  "  if container/platform is quiet
                                        !     (contents not initially listed)
attribute transparent                   !  "  if object is not opaque

attribute workflag                      ! for library use
attribute already_listed alias workflag

attribute special                       ! for miscellaneous use


!----------------------------------------------------------------------------
! RESERVED GLOBALS:
!----------------------------------------------------------------------------

!\ The first 12 are pre-defined by the compiler:

global object                           ! direct object of a verb action
global xobject                          ! indirect object
global self                             ! self-referential object
global words                            ! total number of words
global player                           ! the player object
global actor                            ! player, or a char. (for scripts)
global location                         ! location of the player object
global verbroutine                      ! the verb routine
global endflag                          ! if non-false, run EndGame
global prompt                           ! for input line
global objects                          ! total number of objects
global system_status                    ! after certain operations
\!

global player_person = 2                ! 1=first, 2=second, 3=third

global MAX_SCORE                        ! total possible score
global FORMAT                           ! contains bitmap of format masks
global DEFAULT_FONT                     ! 0=monospaced normal text
global STATUSTYPE                       ! 0=none, 1=score/turns, 2=time
global UNDO_OFF                         ! overrides undo when true

global counter                          ! elapsed turns (or time, as desired)
global score                            ! accumulated score
global verbosity                        ! for room descriptions
global list_nest                        ! used by ListObjects
global light_source                     ! in location
global event_flag                       ! set when something happens
global speaking                         ! if the player is talking to a char.
global old_location                     ! whenever location changes
global last_object                      ! set by Perform to object global
global obstacle                         ! if something is stopping the player
global list_count                       ! number of unlisted objects
global need_newline                     ! true when newline should be printed
global override_indent                  ! true if no indent should be printed
global customerror_flag                 ! true after CustomError is called

array parser_data[5]
! parser_data elements:
constant PARSER_STATUS       0          ! PARSER_STATUS mask
constant LAST_PARSER_STATUS  1
constant BEST_PARSE_RANK     2          ! for matching similarly named objects
constant PARSE_RANK_TESTS    3          ! counter
constant LAST_SINGLE_OBJECT  4          ! for next-turn disambiguation
constant VERB_IS_XVERB       5          ! for this call to Perform()

#ifclear NO_SCRIPTS
constant MAX_SCRIPTS      16            !
constant MAX_SCRIPT_STEPS 32            !
global number_scripts                   ! for object scripts
array scriptdata[48]                    !
array setscript[1024]                   !
#endif

global MAX_RANK                         ! allow for up to 10 levels of
array ranking[10]                       ! player ranking (as a default)

global it_obj                           !
global them_obj                         !
global him_obj                          ! to reference objects via pronouns
global her_obj                          !
array replace_pronoun[4]                !

constant MAX_WORDS 32                   ! in a parsed input line
array oldword[MAX_WORDS]                ! for "again" command

global general                          ! for general use


!----------------------------------------------------------------------------
! COLOR CONSTANTS AND GLOBALS
!----------------------------------------------------------------------------

enumerate                               ! colors 0 to 17
{
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, WHITE,
        DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
        LIGHT_RED, LIGHT_MAGENTA, YELLOW, BRIGHT_WHITE,
        DEF_FOREGROUND, DEF_BACKGROUND,
        DEF_SL_FOREGROUND, DEF_SL_BACKGROUND,
        MATCH_FOREGROUND
}

global TEXTCOLOR        = DEF_FOREGROUND        ! normal text color
global BGCOLOR          = DEF_BACKGROUND        ! normal background color
global SL_TEXTCOLOR     = DEF_SL_FOREGROUND     ! statusline text color
global SL_BGCOLOR       = DEF_SL_BACKGROUND     ! statusline background color
global INPUTCOLOR       = MATCH_FOREGROUND      ! input color


!----------------------------------------------------------------------------
! PARSER STATUS
!
! For parser_data[PARSER_STATUS].  Mask must be reset in Parse, as well as
! after Perform and ParseError.
!----------------------------------------------------------------------------
enumerate step *2
{
        PARSER_RESET,           ! 0, for reset
        PARSER_ACTIVE = 1,
        PRONOUNS_SET,           ! if "it", etc. are used
        FINDOBJECT_KNOWN,       ! if FindObject() encounters a 'known' object
        FINDOBJECT_NONLIVING,   ! if a nonliving object is encountered
        PERFORM_QUEUE           ! one of multiple calls to Perform()
}

!----------------------------------------------------------------------------
! PRINTING FORMAT MASKS
!
! The following are bitmasks added/subtracted from the FORMAT global
! to affect text/list output.  Combine formats using '+' or '|' as in:
!
!       FORMAT = LIST_F | GROUPPLURALS_F | ...
!----------------------------------------------------------------------------

enumerate start = 1, step *2
{
        LIST_F                  ! print itemized lists, not sentences
        NORECURSE_F             ! do not recurse object contents
        NOINDENT_F              ! do not indent listings
        DESCFORM_F              ! alternate room desc. formatting
        GROUPPLURALS_F          ! list plurals together where possible
        NOPARENTHESES_F         ! ignore printing by ObjectIs

! For internal (library) use:

        INVENTORY_F             ! list as player inventory
        FIRSTCAPITAL_F          ! capitalize first article
        ISORARE_F               ! print "is" or "are" at the start
        ISORAREHERE_F           ! print "is here" or "are here" last
        USECHARNAMES_F          ! before listing contents
        TEMPLIST_F              ! used if LIST_F must be overridden
}

global INVENTORY_MASK = 0       ! may be set by DoInventory


!----------------------------------------------------------------------------
! FONT STYLE BITMASKS
!
! Used with the Font routine to set or change the font style.  Combine
! settings using '+' or '|', as in:
!
!       Font(BOLD_ON | ITALIC_OFF | ...)
!----------------------------------------------------------------------------

enumerate start = 1, step *2
{
        BOLD_ON, BOLD_OFF,
        ITALIC_ON, ITALIC_OFF,
        UNDERLINE_ON, UNDERLINE_OFF,

        PROP_ON, PROP_OFF               ! proportional printing
}


!----------------------------------------------------------------------------
! ADDITIONAL CONSTANTS (AND GLOBALS)
!----------------------------------------------------------------------------

constant UP_ARROW       11              ! special keystrokes
constant DOWN_ARROW     10
constant LEFT_ARROW      8
constant RIGHT_ARROW    21
constant ESCAPE_KEY     27
constant ENTER_KEY      13
constant MOUSE_CLICK     1

constant AND_WORD       "and"           ! for language translation
constant ARE_WORD       "are"
constant HERE_WORD      "here"
constant IN_WORD        "in"
constant IS_WORD        "is"
constant ON_WORD        "on"

constant FILE_CHECK     4660            ! for readfile/writefile blocks

#if undefined INDENT_SIZE
constant INDENT_SIZE 2                  ! for paragraph formatting
#endif
#if undefined AFTER_PERIOD
constant AFTER_PERIOD  "  "             ! double-space after period
#endif


!----------------------------------------------------------------------------
! SYNONYMS, COMPOUNDS, AND REMOVALS
!----------------------------------------------------------------------------

synonym "and" for "~and"
synonym "except" for "~except"
synonym "but" for "~except"
synonym "all" for "~all"
synonym "everything" for "~all"
synonym "any" for "~any"
synonym "either" for "~any"
synonym "oops" for "~oops"
synonym "o" for "~oops"
synonym "mine" for "my"
synonym "myself" for "me"
#ifset NO_OBJLIB
synonym "herself" for "her"
synonym "himself" for "him"
synonym "themselves" for "them"
#endif

compound "mr", "."
compound "mrs", "."
compound "dr", "."
compound "st", "."
compound "off", "of"
compound "out", "of"
compound "on", "to"
compound "in", "to"

removal "a", "an", "the", "some", "of"


!----------------------------------------------------------------------------
object nothing "nothing"                ! OBJECT 0:  the great granddaddy
{}

enumerate start = 1, step 1
{
        screenwidth, screenheight,      ! built-in display object read-only
        linelength, windowlines,        ! properties
        cursor_column, cursor_row,
        hasgraphics, title_caption,
        hasvideo, needs_repaint,
        pointer_x, pointer_y
}

property statusline_height alias n_to   ! library-specific display object
                                        ! properties

object display
{
        statusline_height 1
}


!----------------------------------------------------------------------------
! EndGame(end_type)
! called by the engine via EndGame(end_type) when endflag is not false
! (endflag is cleared previous to calling); return false to terminate
!
! Default responses (in PrintEndGame):  1 = win, 2 = die, 0 = no response

routine EndGame(end_type)
{
        PrintStatusLine                 ! update one last time
        PrintEndGame(end_type)          ! print appropriate ending message

#ifclear NO_VERBS
        local r

:AskAgain

        Message(&EndGame, 1)    ! ask to RESTART, RESTORE, (UNDO), or QUIT

        r = -1

        while true
        {
                GetInput
                select word[1]
                        case "restart", "r"
                        {
                                if restart
                                {
                                        r = true
                                        PrintStatusline
                                }
#ifclear NO_XVERBS
                                else
                                        Message(&DoRestart, 2)   ! failed
#endif
                                break
                        }
                        case "restore", "e"
                        {
#ifclear NO_XVERBS
                                r = Perform(&DoRestore)
#else
                                if restore
                                {
                                        r = true
                                        PrintStatusline
                                        DescribePlace(location)
                                }
#endif
                                break
                        }
#ifclear NO_UNDO
                        case "undo", "u"
                        {
                                if not UNDO_OFF
                                {
                                        if undo
                                        {
                                                r = true
                                                PrintStatusLine
                                                DescribePlace(location)
                                        }
#ifclear NO_XVERBS
                                        else
                                                Message(&DoUndo, 1)  ! failed
                                }
                                else
                                        Message(&DoUndo, 1)
#else
                                }
#endif
                                break
                        }
#endif
                        case "quit", "q"
                        {
                                r = 0
                                break
                        }

                Message(&EndGame, 2)    ! ask again (more succinctly)
        }

        if r = -1:  jump AskAgain

        return r

#else   ! i.e., #elseif set NO_VERBS

        return 0;
#endif
}

routine PrintEndGame(end_type)
{
        Font(BOLD_ON)
        select end_type
                case 1:  print "\n*** YOU'VE WON THE GAME! ***"
                case 2
                {
                        if player_person = 2
                                print "\n*** YOU HAVE DIED ***"
                        else
                                print "\n*** "; CThe(player); \
                                        MatchPlural(player, "has", "have"); \
                                        " died! ***"
                }

        Font(BOLD_OFF)
        PrintScore(true)
}

!----------------------------------------------------------------------------
routine PrintScore(end_of_game)
{
        if STATUSTYPE = 1 and MAX_SCORE
        {
                if end_of_game:  print ""
                print "You ";
                if not end_of_game
                        print "have ";
                print "scored a total of ";
                print number score; " out of "; number MAX_SCORE;
                if ranking[0] ~= ""
                {
                        print ", giving you the rank of ";

                        ! A complicated formula, since only
                        ! integer division is allowed:
                        !
                        print ranking[(score*100)/MAX_SCORE*MAX_RANK/100]
                }
                print "."
        }
}

!----------------------------------------------------------------------------
! Parse is called by the engine without parameters after input but before
! any grammar matching; returning true signals the engine to reparse the
! existing input (in case it has been changed)
!
! The engine parser is responsible for splitting the input line into the
! word[] array, removing removals, replacing synonyms, and combining
! compounds.
!
! This Parse routine is then called to take care of:
!       - picking out extra_scenery words
!       - checking for an "again" command
!       - rewording imperatives to "<Name>, <command>"
!       - renaming pronouns to objects
!       - changing "then <do something else>" into a new command
!
! Control then returns to the engine for grammar matching and, if that is
! successful, calling of the matched verb routine.

! NOTE:  There are some snags with the object-based pronoun replacement
! system (such as, for example, requiring a specific object in grammar)
! so OLD_STYLE_PRONOUNS are still being used.
#set OLD_STYLE_PRONOUNS

#ifclear OLD_STYLE_PRONOUNS
! If OLD_STYLE_PRONOUNS is set, the Parse routine will actually change
! the input line by inserting the object name.  This is a different
! approach using actual stand-in objects.
object it_object "it"
{
        is known, hidden
        nouns "it"
        misc { return it_obj }
        parse_rank 1000
        found_in
        {
                local obj
                obj = self.misc
                if FindObject(obj, location)
                        return parent(obj)
                else
                        return false
        }
}

it_object him_object "him"
{
        nouns "him"
        misc { return him_obj }
}

it_object her_object "her"
{
        nouns "her"
        misc { return her_obj }
}

it_object them_object "them"
{
        nouns "them"
        misc { return them_obj }
}
#endif  ! OLD_STYLE_PRONOUNS

routine Parse
{
        local a
        local reparse
        local temp_verb, temp_obj, temp_xobj

        ResetParse

        list_nest = 0
        event_flag = 0

        if nothing ~= 0                   ! best place to check this
                print "[WARNING:  Objects/classes defined before library]"

#ifset DEBUG
        if debug_flags & D_PARSE_RANK
        {
                print "[parser_data[BEST_PARSE_RANK] = 0]"
        }
#endif

#ifclear OLD_STYLE_PRONOUNS
        ! Only need to set up all attributes once, so that a given
        ! pronoun will satisfy any grammatical attribute requirements
        if it_object is not 127
        {
                local i
                for (i=0; i<128; i++)
                {
                        it_object is i
                        him_object is i
                        her_object is i
                        them_object is i
                }
        }
#endif

        if word[1] = "~oops"
                return

        ! Allow the player object to override the parsing cycle completely
        temp_verb = verbroutine
        temp_obj = object
        temp_xobj = xobject
        verbroutine = &PreParse
        object = nothing
        xobject = nothing
        if player.before
        {
                verbroutine = temp_verb
                object = temp_obj
                xobject = temp_xobj
                parser_data[PARSER_STATUS] = 0
                parser_data[LAST_PARSER_STATUS] = 0
                return false
        }
        verbroutine = temp_verb
        object = temp_obj
        xobject = temp_xobj

! The following, devised by Jim Newland, checks to see if the player
! input refers to an unnecessary item of scenery (for example) which is
! nonetheless mentioned in the location description.

        for (a=2; a<=words and word[a]~="" and word[a]~="then"; a++)
        {
                if Inlist(location, extra_scenery, word[a])
                {
                        Message(&Parse, 1)
                        word[1] = ""            ! force ParseError(0)
                        words = 0
                        customerror_flag = true
                        return true
                }
        }

        if PreParse:  reparse = true            ! easily replaceable routine

        ! Last player-specified object
        if object > 0 and object < objects and last_object ~= -1
                AssignPronoun(object)
        parser_data[LAST_PARSER_STATUS] = 0

        ! Must do this after AssignPronoun, and reset it to 0
        ! after both of Perform and ParseError:
        parser_data[PARSER_STATUS] = PARSER_ACTIVE

#ifclear OLD_STYLE_PRONOUNS
        move it_object to parent(it_obj)
        move him_object to parent(him_obj)
        move her_object to parent(her_obj)
        move them_object to parent(them_obj)
#endif

        ! To repeat last command
        if (word[1] = "again" or word[1] = "g") and word[2] = ""
        {
                for (a=1; a<=oldword[0]; a++)
                        word[a] = oldword[a]
                words = oldword[0]
                reparse = true
                jump LeaveParse
        }

        local count
#ifset OLD_STYLE_PRONOUNS
        local n, number_pronouns
#endif

        for (count=2; count<=words and word[count]~=""; count++)
        {
                select word[count]

#ifset OLD_STYLE_PRONOUNS
                        ! Rename pronouns to appropriate objects
                        case "it", "them", "him", "her"
                        {
                                select word[count]
                                        case "it":      a = it_obj
                                        case "them":    a = them_obj
                                        case "him":     a = him_obj
                                        case "her":     a = her_obj

                                if a = nothing
                                {
                                        ! "...be a little more specific"
                                        ParseError(13)
                                        words = 0
                                        customerror_flag = true
                                        return
                                }
                                ! Avoid, e.g., "put it it something"
                                elseif word[count] ~= word[count+1]
                                {
                                        ! For her_obj, we can run into trouble, since
                                        ! it's both possessive and a pronoun, so only
                                        ! replace "her" where it's the last word:
                                        if a ~= her_obj or
                                                (a = her_obj and (count = 2 or count = words))
                                        {
                                                n = SetObjWord(count, a)
                                                replace_pronoun[number_pronouns] = a
                                                number_pronouns++
                                                if n > 1
                                                        count = count + (n - 1)
                                                parser_data[PARSER_STATUS] |= PRONOUNS_SET
                                                reparse = true
                                        }
                                }
                        }
#endif

                        ! Allow for "then..." and "and then..."
                        case "then"
                        {
                                ! end of this command
                                word[count] = "."
                                if word[count-1] = "~and"
                                        DeleteWord(count-1)
                                reparse = true
                                break
                        }
        }

#ifset OLD_STYLE_PRONOUNS
        if number_pronouns = 2 and replace_pronoun[0] = replace_pronoun[1]
                number_pronouns--

        if number_pronouns > 0
        {
                PrintReplacedPronouns(number_pronouns)
        }
#endif

! Reword imperatives given as "Tell Bob to do something" as "Bob, do
! something" so that the engine automatically reroutes them to SpeakTo

        if word[1] = "tell", "order", "instruct", "ask", "command"
        {
                for (a=1; a<=words and word[a]~=""; a++)
                {
                        if word[a] = "to"
                        {
                                !DeleteWord(a)   ! "to"
                                word[a] = "~and"
                                DeleteWord(1)   ! "tell", "order", etc.
                                reparse = true
                                break
                        }
                }
        }

#ifset USE_PLURAL_OBJECTS
        if ParsePluralObjects:  reparse = true
#endif

#ifset USE_CHECKHELD
        ParseCheckHeld
#endif

        ! Store current command for future reference
        local ow
        for (a=1; a<=words and a<MAX_WORDS; a++)
        {
                if word[a] = "g", "again"
                {
                        if word[a+1] = ""
                                a++
                }
                else
                        oldword[++ow] = word[a]
        }
        oldword[a] = ""
        oldword[0] = ow

:LeaveParse

#ifset DEBUG
        if debug_flags & D_PARSE
        {
                Font(BOLD_ON)
                for (a=1; a<=words and word[a]~=""; a++)
                        print "["; word[a]; "] ";
                print newline
                if parse$ ~= ""
                        print "[parse$ = \""; parse$; "\"]"
                Font(BOLD_OFF)
        }
#endif

        return reparse
}

routine ResetParse
{
        customerror_flag = false
        parser_data[BEST_PARSE_RANK] = 0  ! reset each parser cycle
        parser_data[PARSE_RANK_TESTS] = 0
        parser_data[VERB_IS_XVERB] = 0
}

routine PreParse                        ! to be replaced if needed
{}

routine CurrentCommandWords
{
        if words = 0
                return 0

        local i
        for (i=1; i<words; i++)         ! not <=, because of the i++
        {
                if word[i] = ""
                        break
        }
        return i
}

routine SetObjWord(a, obj)      ! inserts unique name of <obj> at word <a>
{
        local i, n

        if obj.#adjectives              ! Allowing multiple adjectives...
        {
                for (i=1; i<=obj.#adjectives; i++)
                {
                        if obj.adjective #i
                        {
                                if ++n > 1:  InsertWord(a)
                                word[a] = obj.adjective #i
                                a++
                        }
                        if i = 15: break        ! match MAX_MOBJ in heparse.c
                }
        }

        if obj.#nouns                    ! ...and 1 noun (obj.noun #1)
        {
                for (i=1; i<=obj.#nouns; i++)
                {
                        if obj.noun #i
                        {
                                if n:  InsertWord(a)
                                word[a] = obj.noun #i
                                break
                                ! Never executed:
                                !a++ : n++
                        }
                }
        }

        return n
}

routine InsertWord(p, n)                ! inserts <n> words at position <p>
{
        local i

        if n = 0:  n = 1

        if words+n >= MAX_WORDS:  return

        for (i=words+n; i>p; i--)
                word[i] = word[i-n]
        words = words + n

        return n
}

routine DeleteWord(p, n)                ! deletes <n> words at position <p>
{
        local i

        if n = 0:  n = 1

        if (words < n) or (p + n >= MAX_WORDS):  return

        for (i=p; i<=words-n; i++)
                word[i] = word[i+n]
        word[words] = ""
        words = words - n

        return n
}

routine VerbWord(which)                 ! returns word used as verb
{                                       ! in a typed command
        select verbroutine
        case &DoLook
        {
                if word[1] = "x"
                        return "examine"
        }
        case else
                return word[1]
}

routine ObjWord(wd, obj)                ! returns adjective or noun if <wd>
{                                       ! is either for <obj>
        if InList(obj, noun, wd)
                return noun

        if InList(obj, adjective, wd)
                return adjective

        return false                    ! didn't match either
}

routine PrintReplacedPronouns(number_pronouns)
{
        local count

        Message(&Parse, 2)      ! "Assuming you mean..."
        for (count = 0; count < number_pronouns; count++)
        {
                if count > 0
                {
                        if number_pronouns > 2
                                print ",";
                        if count = number_pronouns - 1
                                print " "; AND_WORD;
                }
                print " ";

                if replace_pronoun[count].name = ""
                        The(nothing)
                else
                        The(replace_pronoun[count])
        }
        if number_pronouns > 1
                Message(&Parse, 3)      ! ", respectively"
        print ")"
}

!----------------------------------------------------------------------------
! ParseError(errornumber, object)
! prints an appropriate error message; if called by the engine, signals the
! engine to produce the default message by returning false
!
! (Note:  If <errornumber> is equal to or greater than 100, CustomError
! is called instead.  Replace CustomError for cases where custom error
! messages are desired for user parsing routines.  Do not call CustomError
! directly.  NewParseError can be replaced to modify only some
! messages.)

routine ParseError(errornumber, obj)
{
        local r
        r = NewParseError(errornumber, obj)
        if r
        {
                parser_data[PARSER_STATUS] = PARSER_RESET
                return r
        }

        if errornumber >= 100
        {
                CustomError(errornumber, obj)
                word[1] = ""            ! force ParseError(0)
                words = 0
                customerror_flag = true
                parser_data[PARSER_STATUS] = PARSER_RESET
                return true
        }
        if customerror_flag
        {
                customerror_flag = 0    ! CustomError already printed error
                parser_data[PARSER_STATUS] = PARSER_RESET
                return true
        }

#ifset DEBUG
        if debug_flags & D_PARSE
        {
                Font(BOLD_ON)
                print "[ParseError("; number errornumber; ", "; obj.name; \
                        " ("; number obj; ")]"
                Font(BOLD_OFF)
        }
#endif

        select errornumber

                case 1
                        print CThe(player); \
                                ! " can't use the word \""; \
                                MatchPlural(player, "doesn't", "don't"); \
                                " need to use the word \""; \
                                parse$; "\"."

                case 3
                        print CThe(actor); " can't "; parse$; " multiple
                                objects like that."

                case 5
                {
                        if VerbWord = "give", "offer", "hand", "show"
                        {
                                print "Not sure what you're referring to--try \""; \
                                        VerbWord; " (something) \Ito\i (someone)\"."
                        }
                        else
                        {
!\
                                print CThe(player); \
                                        MatchPlural(player, "hasn't", "haven't");
                                        print " seen any";
#ifset OLD_STYLE_PRONOUNS
                                        ! If we built an object phrase using
                                        ! OLD_STYLE_PRONOUNS, avoid printing a
                                        ! potential nonsense name:
                                        if parser_data[PARSER_STATUS] & PRONOUNS_SET
                                                print "thing like that";
                                        else
#endif
                                                print " \""; parse$; "\"";
                                        print ", nor"; IsorAre(player, true); " "; The(player); \
                                        " likely to, even if such a thing exists."
\!
                                print CThe(player); \
                                        MatchPlural(player, "hasn't", "haven't");
                                        print " encountered any";
#ifset OLD_STYLE_PRONOUNS
                                if parser_data[PARSER_STATUS] & PRONOUNS_SET
                                        print "thing like that";
                                else
#endif
                                        print " \""; parse$; "\"";
                                print ".";
                                print "  (If you're sure you need to refer to that, try
                                        putting it another way.)"
                        }
                }
                case 6
                        print "That doesn't make any sense."

                case 9
                {
                        print "Nothing to ";
                        if verbroutine
                                print parse$; "."
                        else:  print "do."
                }

                case 10
                {
                        print CThe(player); \
                          MatchPlural(player, "hasn't", "haven't");
                        if &obj.long_desc
                                " seen ";
                        else
                                " encountered ";
                        if obj is living and not (parser_data[PARSER_STATUS] & FINDOBJECT_NONLIVING)
                                print "anybody";
                        else:  print "anything";
                        print " like that";
#ifset DEBUG
                        if (debug_flags & D_OBJNUM)
                                print " ["; number obj; "]";
#endif
                        print "."
                }

                case 11
                {
                        if not ParseError_ObjectIsKnown(obj)
                        {
                                ParseError(10, obj)
                        }
                        elseif obj is living
                        {
!\
                                print CThe(obj); \
                                        MatchPlural(obj, "isn't", "aren't"); " here."
\!
                                print CThe(actor); \
                                        MatchPlural(actor, "doesn't", "don't"); \
                                        " see";
                                if obj is plural
                                        " them";
                                elseif obj is female
                                        " her";
                                else
                                        " him";
#ifset DEBUG
                                if (debug_flags & D_OBJNUM)
                                        print " ["; number obj; "]";
#endif
                                print "."
                        }
                        else
                        {
#ifset USE_CHECKHELD
                                if verbroutine = &DoDrop_CheckHeld, &DoPutIn_CheckHeld,
                                        &DoPutonGround_CheckHeld
                                {
                                        ParseError(15, obj)
                                }
                                else
                                {
#endif
                                        print CThe(actor); \
                                                MatchPlural(actor, "doesn't", "don't"); \
                                                " see that"; ! MatchPlural(obj, "that", "those");
#ifset DEBUG
                                        if (debug_flags & D_OBJNUM)
                                                print " ["; number obj; "]";
#endif
                                        print "."
#ifset USE_CHECKHELD
                                }
#endif
                        }
                }

                case 12
                {
                        if not ParseError_ObjectIsKnown(obj)
                        {
                                ParseError(10, obj)
                        }
                        else
                        {
                                print CThe(actor); \
                                        " can't do that with "; TheOrThat(obj) ; "."
                        }
                }
                case 13
                        print "You'll have to be a little more specific."

                case 14
                {
                        if not ParseError_ObjectIsKnown(obj)
                        {
                                ParseError(10, obj)
                        }
                        elseif xobject is living
                        {
                                print CThe(xobject); \
                                        MatchPlural(xobject, "doesn't", "don't"); \
                                        " have "; TheOrThat(obj); "."
                        }
                        else
                        {
                                print CThe(actor); \
                                        MatchPlural(actor, "doesn't", "don't"); \
                                        " see "; TheOrThat(obj); " there."
                        }
                }

                case 15
                {
                        if not ParseError_ObjectIsKnown(obj)
                        {
                                ParseError(10, obj)
                        }
                        elseif obj = player
                        {
                                ParseError(12, obj)
                        }
                        else
                        {
                                print CThe(actor); IsorAre(actor); " not
                                        holding"; MatchPlural(obj, "that", "those"); "."
                        }
                }

                case else
                {
                        parser_data[PARSER_STATUS] = PARSER_RESET
                        return false            ! print the default message
                }

        parser_data[PARSER_STATUS] = PARSER_RESET
        return true                             ! message already printed
}

routine ParseError_ObjectIsKnown(obj)
{
        if ObjectIsKnown(obj)
                return true
        if parser_data[PARSER_STATUS] & FINDOBJECT_KNOWN  ! and not xobject
                return true
        return false
}

routine TheOrThat(obj)
{
        if obj is known
                print The(obj);
        else
                print "that";
}

routine NewParseError(errornumber, obj) ! to be replaced for custom error
{}                                      ! messages for library parsing

routine CustomError(errornumber, obj)   ! to be replaced for custom error
{}                                      ! messages for user parsing routines

!----------------------------------------------------------------------------
! SpeakTo is called by the engine when a command is addressed to a
! character object via:  SpeakTo(character)
!
! For example, the input line
!
!   <character>, get the <object>
!
! will call SpeakTo(<character>), with the global object containing <object>,
! and the verbroutine global set to &DoGet

routine SpeakTo(char)
{
#ifset USE_CHECKHELD
        if verbroutine = &DoDrop_CheckHeld
                verbroutine = &DoDrop
        elseif verbroutine = &DoPutIn_CheckHeld
                verbroutine = &DoPutIn
#endif

#ifset VERBSTUBS
        if verbroutine = &DoHelpChar and object = player
        {
                verbroutine = &DoHelp
                object = nothing
        }
#endif

#ifset USE_CHECKHELD
        ResetCheckHeld
#endif

#ifset DEBUG
        if debug_flags & D_PARSE
        {
                print "\B[Speakto("; char.name;
                if (debug_flags & D_OBJNUM)
                        print " ["; number char; "]";
                print ") verbroutine="; number verbroutine;
                print ", object="; object.name;
                if (debug_flags & D_OBJNUM)
                        print " ["; number object; "]";
                print ", xobject="; xobject.name;
                if (debug_flags & D_OBJNUM)
                        print " ["; number xobject; "]";
                print "]\b"
        }
#endif

        speaking = 0

        if char is not living
        {
                ParseError(6)
                return
        }

        AssignPronoun(char)

        ! Handle player/typist-related ParseError messages:
        if not FindObject(char, location)
        {
                actor = player
                ParseError(11, char)
                return
        }
        elseif char = player
        {
                actor = player
                Message(&Speakto, 1)    ! "Stop talking to yourself..."
                return
        }
        elseif not ObjectisKnown(object) and not FindObject(object, location)
        {
                actor = player
                ParseError(10, object)
                return
        }

        if char is unfriendly
                jump IgnorePlayer

        speaking = char

        ! In the event of:  >CHARACTER, GO NORTH.  GET THE THING.  GO WEST., etc.
        if not FindObject(char, location)
        {
                run char.order_response
                return true
        }

        select verbroutine
                case 0                  ! Just the character name is given,
                                        ! so just "X is listening."
                {
                        if not char.order_response
                                Message(&Speakto, 2, char)
                }

#ifclear NO_VERBS
                case &DoHello           ! Note the ampersands ('&')--or else
                {                       ! the routines themselves would run
                        if not char.order_response
                        {
                                if char is not unfriendly
                                        ! "X nods hello."
                                        Message(&Speakto, 3, char)
                                else
                                {
                                        jump IgnorePlayer
                                }
                        }
                }

                case &DoAskQuestion
                        return Perform(&DoAsk, char, object)

                case &DoTalk
                {
                        if xobject
                                ParseError(6)
                        else
                                return Perform(&DoAsk, char, object)
                }

                case &DoTell
                {
                        if object = player
                                return Perform(&DoAsk, char, xobject)
                        else
                                jump TryResponse
                }
#endif  ! ifclear NO_VERBS

                case else
                {

! If the character can respond to a request, this should be dealt with by
! an order_response property routine; order_response--if it exists--should
! return false if there is no response for the given verbroutine

:TryResponse

                        if not char.order_response
                                jump IgnorePlayer
                        return true
                }
        return false

:IgnorePlayer

        if not char.ignore_response
                Message(&Speakto, 4, char)      ! "X ignores you."
        return false
}

!----------------------------------------------------------------------------
! Perform(&action, object, xobject)
! calls the verbroutine given by <action>, with globals object and xobject
! as given; returns value returned by <action> (or <object>.before)
!
! NOTE:  Ensure that the <action> is an address (preceded by &), not a
! standard routine call.
!
! (The <queue> argument is used by the library when calling Perform
! for each object in a set of multiple objects.)
!
! (<isxverb> is true when the action being called is as a result of
! an xverb grammar line.)

routine Perform(action, obj, xobj, queue, isxverb)
{
        local r
        local objtemp, xobjtemp, verbtemp, actortemp
#ifclear NO_XVERBS
        local restoring
        if verbroutine = &DoRestore:  restoring = true
#endif

#ifset DEBUG
        if debug_flags & D_PARSE
        {
                print "\B[Perform("; number action; ", "; obj.name;
                if (debug_flags & D_OBJNUM) or queue = -1
                        print " ["; number obj; "]";
                print ", "; xobj.name;
                if (debug_flags & D_OBJNUM) or queue = -1
                        print " ["; number xobj; "]";
                if queue
                        print ", "; number queue;
                print ")]\b"
        }
#endif

        if queue
                parser_data[PARSER_STATUS] |= PERFORM_QUEUE

        if not queue and object
                parser_data[LAST_SINGLE_OBJECT] = object
        else
                parser_data[LAST_SINGLE_OBJECT] = 0

        parser_data[VERB_IS_XVERB] = isxverb

        objtemp = object
        xobjtemp = xobject
        verbtemp = verbroutine
        actortemp = actor

        object = obj
        xobject = xobj
        verbroutine = action
        actor = player

#ifclear OLD_STYLE_PRONOUNS
        local number_pronouns = 0
        if object = it_object:          object = it_obj
        elseif object = him_object:     object = him_obj
        elseif object = her_object:     object = her_obj
        elseif object = them_object:    object = them_obj
        if object ~= obj
        {
                replace_pronoun[number_pronouns] = object
                number_pronouns++
        }
        if xobject = it_object:         xobject = it_obj
        elseif xobject = him_object:    xobject = him_obj
        elseif xobject = her_object:    xobject = her_obj
        elseif xobject = them_object:   xobject = them_obj
        if xobject ~= xobj
        {
                replace_pronoun[number_pronouns] = xobject
                number_pronouns++
        }
        if number_pronouns
        {
                parser_data[PARSER_STATUS] |= PRONOUNS_SET
                PrintReplacedPronouns(number_pronouns)
        }
#endif

#ifclear NO_OBJLIB
        SetupDirectionObjects
#endif

        ! Itemize each object in a list of multiple objects
        if queue > 0 and object > display
        {
#ifset USE_CHECKHELD
                ! Check if an ImplicitTakeForDrop was just done, meaning we
                ! need a newline before printing the next "object:"
                if checkheld is workflag
                        print ""
                checkheld is not workflag
#endif
                print object.name; ":  ";
        }

        r = BeforeRoutines(queue)
        if r:  jump DonePerform

        r = call action                 ! object.after and xobject.after
                                        ! run by verbroutine
#ifclear NO_XVERBS
        if restoring
                verbroutine = &DoRestore
#endif
        if r
        {
                AfterRoutines
        }

:DonePerform

#ifset USE_CHECKHELD
        ResetCheckHeld
#endif

        last_object = object

        verbroutine = verbtemp
        object = objtemp
        xobject = xobjtemp
        actor = actortemp

        if queue = -1
                last_object = -1
        parser_data[PARSER_STATUS] = PARSER_RESET

        return r
}

#ifclear NO_OBJLIB
routine SetupDirectionObjects
{
        ! Chris Tate devised this method for setting the [x]object to a
        ! direction if it hasn't yet been done:
        if not object or not xobject
        {
                local i, wordnum

                ! The last word in the command might be a direction, e.g. in the grammar for
                ! >PUSH OBJECT NORTH or >OUT.  If we don't see an object or xobject we might
                ! need to parse the last word as a direction and supply that.
                wordnum = words
                for (i=1; i<=words; i++)
                {
                        if word[i] = ""
                        {
                                wordnum = i - 1
                                break
                        }
                }

                for i in direction
                {
                        if i.type = direction and ObjWord(word[wordnum], i)
                        {
                                ! The last word is a direction.  If there's no object we
                                ! make that the direction object; otherwise we make it the
                                ! xobject.
                                if not object
                                {
                                        AssignPronoun(i)
                                        object = i
                                }
                                else
                                        xobject = i
                                break
                        }
                }
        }
}
#endif  ! ifclear NO_OBJLIB

!----------------------------------------------------------------------------
! BeforeRoutines(queue)
!
! Runs all relevant routines that might precede a verbroutine, returning
! true if any of them returns true.
!----------------------------------------------------------------------------

routine BeforeRoutines(queue)
{
        local r, i

        r = player.react_before
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; player.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number player; "]";
                        print ".react_before returned "; number r; "]\b"
                }
#endif
                return r
        }
        r = player.before
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; player.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number player; "]";
                        print ".before returned "; number r; "]\b"
                }
#endif
                return r
        }

        r = location.react_before
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; location.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number location; "]";
                        print ".react_before returned "; number r; "]\b"
                }
#endif
                return r
        }
        r = location.before
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; location.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number location; "]";
                        print "before returned "; number r; "]\b"
                }
#endif
                return r
        }

        for i in location
        {
                r = i.react_before
                if r
                {
#ifset DEBUG
                        if debug_flags & D_PARSE
                        {
                                print "\B["; i.name;
                                if debug_flags & D_OBJNUM
                                        print " ["; number i; "]";
                                print ".react_before returned "; number r; "]\b"
                        }
#endif
                        return r
                }
        }

        ! queue is -1 if the object was a number (i.e., a literal digit)
        if queue ~= -1 and xobject > display
        {
                r = xobject.before
                if r
                {
#ifset DEBUG
                        if debug_flags & D_PARSE
                        {
                                print "\B["; xobject.name;
                                if debug_flags & D_OBJNUM
                                        print " ["; number xobject; "]";
                                print ".before returned "; number r; "]\b"
                        }
#endif
                        return r
                }
        }

        if queue ~= -1 and object > display
        {
                r = object.before
                if r
                {
#ifset DEBUG
                        if debug_flags & D_PARSE
                        {
                                print "\B["; object.name;
                                if debug_flags & D_OBJNUM
                                        print " ["; number object; "]";
                                print ".before returned "; number r; "]\b"
                        }
#endif
                        return r
                }
        }
}

!----------------------------------------------------------------------------
! AfterRoutines
!
! Runs all relevant routines that might follow a verbroutine.  Note that
! object.after and xobject.after are not called here, nor is anything that
! should be explicitly called by a verbroutine depending on its (degree of)
! failure or success.
!----------------------------------------------------------------------------

routine AfterRoutines
{
        local i, r

        r = player.after
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; player.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number player; "]";
                        print ".after returned "; number r; "]\b"
                }
#endif
        }

        r = player.react_after
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; player.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number player; "]";
                        print ".react_after returned "; number r; "]\b"
                }
#endif
        }

        r = location.after
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; location.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number location; "]";
                        print ".after returned "; number r; "]\b"
                }
#endif
        }

        r = location.react_after
        if r
        {
#ifset DEBUG
                if debug_flags & D_PARSE
                {
                        print "\B["; location.name;
                        if debug_flags & D_OBJNUM
                                print " ["; number location; "]";
                        print ".react_after returned "; number r; "]\b"
                }
#endif
        }

        for i in location
        {
                r = i.react_after
                if r
                {
#ifset DEBUG
                        if debug_flags & D_PARSE
                        {
                                print "\B["; i.name;
                                if debug_flags & D_OBJNUM
                                        print " ["; number i; "]";
                                print ".react_after returned "; number r; "]\b"
                        }
#endif
                }
        }
}

!----------------------------------------------------------------------------
! AnyVerb(obj)
! returns <obj> if the verbroutine global applies to a verb as opposed to
! an xverb; otherwise returns false

routine AnyVerb(obj)
{
#ifclear NO_XVERBS
        if parser_data[VERB_IS_XVERB]
                return false
#endif
        if obj
                return obj
        else
                return true
}


!----------------------------------------------------------------------------
! VerbHeldMode(word)
! returns -1 if a verb requires an explicitly notheld object, 1 for an
! explicitly held object, or 0 for no explicit requirement.

routine VerbHeldMode(w)
{
        if w = "get", "take", "grab", "pick", "remove"
        {
                return -1                       ! explicitly notheld
        }
        elseif w = "drop", "put", "leave", "place", "throw", "insert",
                "give", "offer"
        {
                return 1                        ! explicitly held
        }
        return 0
}


!----------------------------------------------------------------------------
! InList(object, property, val)
! returns false if <val> is not contained in the list of values held in
! <object>.<property>; otherwise returns the number of the (first) property
! element equal to <val>

routine InList(obj, prop, val)
{
        local i

        for (i=1; i<=obj.#prop; i++)
        {
                if obj.prop #i = val:  return i
        }
}

!----------------------------------------------------------------------------
! IsPossibleXobject(obj)
! returns true if <obj> is potentially an xobject

routine IsPossibleXobject(obj)
{
        local i
        for (i=1; i<words; i++)
        {
                if word[i] = ""
                {
                        i--
                        break
                }
        }
        if ObjWord(word[i], obj)
                return true
}

!----------------------------------------------------------------------------
! FindObject(object, object location)
! returns false if <object> is unavailable in <object location>; returns
! 2 if <object> is visible but not physically accessible

routine FindObject(obj, objloc, recurse)
{
        local a, p
        local this_parse_rank
        local found_result = true

        if obj = nothing or obj = player
        {
                if obj = nothing and not recurse
                {
#ifset DEBUG
                        if debug_flags & D_FINDOBJECT
                        {
                                print "[Resetting FindObject]"
                        }
                        if debug_flags & D_PARSE_RANK
                        {
                                print "[parser_data[BEST_PARSE_RANK] = 0]"
                        }
#endif
                        parser_data[BEST_PARSE_RANK] = 0
                        parser_data[PARSE_RANK_TESTS] = 0
                        parser_data[PARSER_STATUS] &= ~FINDOBJECT_KNOWN
                        parser_data[PARSER_STATUS] &= ~FINDOBJECT_NONLIVING
                }
                elseif obj = player
                {
                        this_parse_rank = obj.parse_rank
                        if this_parse_rank > parser_data[BEST_PARSE_RANK]
                                parser_data[BEST_PARSE_RANK] = this_parse_rank
                }

                ! nothing and player are always available
                obj is known
                return true
        }

#ifclear NO_FUSES
        if obj.type = fuse or obj.type = daemon
        {
                ! Optimize checking of simple fuses and daemons:
                if obj.#in_scope = 1 and not &obj.in_scope and not obj.#found_in and not &obj.found_in
                {
                        if obj is active and obj.in_scope = player
                                return true
                        else
                                return false
                }
        }
#endif

        ! Do some parse_rank tweaking to rank lower objects which (probably) don't
        ! apply to a particular command, like trying to open something that's
        ! already open:
        this_parse_rank = obj.parse_rank

        ! And be ready to prefer the last specifically referred to object in
        ! the event of disambiguation
        if obj = parser_data[LAST_SINGLE_OBJECT]
                this_parse_rank++

#ifclear NO_VERBS
        select verbroutine
        case &DoOpen
        {
                if obj is openable and obj is open
                        this_parse_rank--
        }
        case &DoClose
        {
                if obj is openable and obj is not open
                        this_parse_rank--
        }
        case &DoSwitchOn
        {
                if obj is switchable and obj is switchedon
                        this_parse_rank--
        }
        case &DoSwitchOff
        {
                if obj is switchable and obj is not switchedon
                        this_parse_rank--
        }
        case &DoWear
        {
                if obj is clothing and obj is worn
                        this_parse_rank--
        }
        case &DoTakeOff
        {
                if obj is clothing and obj is not worn
                        this_parse_rank--
        }
#endif  ! #ifclear NO_VERBS

#ifset USE_CHECKHELD
        if checkheld is active
        {
                if checkheld is plural          ! >DROP ALL, etc. ...
                {
                        if (verbroutine = &DoDrop_CheckHeld, &DoPutonGround_CheckHeld) or
                                (verbroutine = &DoPutIn_CheckHeld and xobject)
                        {
                                if obj is not checkheld_flag
                                {
#ifset DEBUG
                                        if debug_flags & D_FINDOBJECT
                                        {
                                                print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                                        objloc.name; " ["; number objloc; "]):  "; \
                                                        "false (not checkheld_flag)]"
                                        }
#endif
                                        return false
                                }
                        }
                }
                elseif obj is checkheld_flag    ! ...or >DROP OBJECT, etc.
                {
                        if (verbroutine = &DoDrop_CheckHeld, &DoPutonGround_CheckHeld) or
                                (verbroutine = &DoPutIn_CheckHeld and xobject)
                        {
                                this_parse_rank += 100
                        }
                }
        }
#endif  ! USE_CHECKHELD

        ! The objloc argument is equal to 0 if a) the grammar token is
        ! "anything", or b) the engine is re-testing object availability
        ! given the setting of parser_data[BEST_PARSE_RANK] during the first
        ! pass of object disambiguation.

        if objloc = 0
        {
#ifclear NO_VERBS
                if verbroutine = &DoGet and not recurse
                {
                        if obj in player
                        {
#ifset DEBUG
                                if debug_flags & D_FINDOBJECT
                                {
                                        print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                                objloc.name; " ["; number objloc; "]):  "; \
                                                "false (object in player)]"
                                }
#endif
                                return false
                        }
                }
#endif
                if location
                {
                        if FindObject(obj, location, true)
                                object is known
                }

                if not ObjectIsKnown(obj)
                {
#ifset DEBUG
                        if debug_flags & D_FINDOBJECT and not recurse
                        {
                                print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                        objloc.name; " ["; number objloc; "]):  "; \
                                        "false (object not 'known')]"
                        }
#endif
                        return false
                }

                if not recurse
                {
                        if parser_data[PARSE_RANK_TESTS]++ = 0
                        {
#ifset DEBUG
                                if debug_flags & D_FINDOBJECT and not recurse
                                {
                                        print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                                objloc.name; " ["; number objloc; "]):  "; \
                                                "true]"
                                }
                                if debug_flags & D_PARSE_RANK and this_parse_rank > parser_data[BEST_PARSE_RANK]
                                {
                                        print "[parser_data[BEST_PARSE_RANK] = "; number this_parse_rank; "]"
                                }
#endif
                                parser_data[BEST_PARSE_RANK] = this_parse_rank
                                return true
                        }

                        if this_parse_rank < parser_data[BEST_PARSE_RANK]
                        {
#ifset DEBUG
                                if debug_flags & D_FINDOBJECT and not recurse
                                {
                                        print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                                objloc.name; " ["; number objloc; "]):  "; \
                                                "false (this_parse_rank = "; number this_parse_rank; \
                                                " < parser_data[BEST_PARSE_RANK] = "; number parser_data[BEST_PARSE_RANK]; ")]"
                                }
#endif
                                return false
                        }
                        else
                        {
#ifset DEBUG
                                if debug_flags & D_PARSE_RANK and this_parse_rank > parser_data[BEST_PARSE_RANK]
                                {
                                        print "[parser_data[BEST_PARSE_RANK] = "; number this_parse_rank; "]"
                                }
#endif
                                parser_data[BEST_PARSE_RANK] = this_parse_rank
                        }
                }

#ifset DEBUG
                if debug_flags & D_FINDOBJECT and not recurse
                {
                        print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                objloc.name; " ["; number objloc; "]):  "; \
                                "true]"
                }
#endif
                return true
        }

        if word[2] = "~all" or word[3] = "~all" and not recurse
        {
                if not IsPossibleXobject(obj) or (xobject and xobject ~= obj)
                {
                        a = obj.exclude_from_all
                        if a < 2
                        {
                                if a or ExcludeFromAll(obj) = true
                                {
#ifset DEBUG
                                        if debug_flags & D_FINDOBJECT and not recurse
                                        {
                                                print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                                        objloc.name; " ["; number objloc; "]):  "; \
                                                        "false (excluded from \"all\")]"
                                        }
#endif
                                        return false
                                }
                        }
                }
        }

        if obj is not living
                parser_data[PARSER_STATUS] |= FINDOBJECT_NONLIVING

        p = parent(obj)

        ! If any object FindObject is attempting to disambiguate
        ! is known, make a note of it (if during the parsing phase)
        if parser_data[PARSER_STATUS] & PARSER_ACTIVE
        {
                if ObjectisKnown(obj)
                        parser_data[PARSER_STATUS] |= FINDOBJECT_KNOWN
        }

        if obj = objloc or
                (player in obj and obj ~= objloc and (obj~=location or not recurse)) or
                p = obj or p = objloc or p = player
        {
                obj is known
                jump FindObjectFound
        }
        elseif (p is not openable or p is platform) and p is not quiet and
                p ~= nothing
        {
                if FindObject(p, objloc, true) and ObjectisKnown(p)
                {
                        obj is known
                        jump FindObjectFound
                }
        }
        elseif p is openable and p is open and p is not quiet and
                p ~= nothing
        {
                if FindObject(p, objloc, true) and ObjectisKnown(p)
                {
                        obj is known
                        jump FindObjectFound
                }
        }
        elseif (p is openable, not open, transparent, not quiet) and
                p ~= nothing
        {
                if FindObject(p, objloc, true) and ObjectisKnown(p)
                {
                        obj is known
                        found_result = 2
                        jump FindObjectFound
                }
        }

        if obj.#found_in
        {
                for (a=1; a<=obj.#found_in; a++)
                {
                        if obj.found_in #a and (obj.found_in #a = objloc or
                                FindObject(obj.found_in #a, objloc, true))
                        {
                                obj is known
                                jump FindObjectFound
                        }
                }
        }

        if obj.#in_scope
        {
                for (a=1; a<=obj.#in_scope; a++)
                {
                        if obj.in_scope #a
                        {
                                if obj.in_scope #a=objloc or obj.in_scope #a=actor
                                {
                                        obj is known
                                        jump FindObjectFound
                                }
                                if FindObject(obj.in_scope #a, objloc, true)
                                {
                                        obj is known
                                        jump FindObjectFound
                                }
                        }
                }
        }

#ifset DEBUG
        if debug_flags & D_FINDOBJECT and not recurse
        {
                if obj.type ~= fuse and obj.type ~= daemon
                {
                        print "[FindObject("; obj.name; " ["; number obj; "], "; \
                                objloc.name; " ["; number objloc; "]):  "; \
                                "false]"
                }
        }
#endif
        return false

:FindObjectFound
        if not recurse
        {
                if parser_data[PARSE_RANK_TESTS]++ = 0
                {
#ifset DEBUG
                        if debug_flags & D_PARSE_RANK and this_parse_rank > parser_data[BEST_PARSE_RANK]
                        {
                                print "[parser_data[BEST_PARSE_RANK] = "; number this_parse_rank; "]"
                        }
#endif
                        parser_data[BEST_PARSE_RANK] = this_parse_rank
                }
                elseif this_parse_rank > parser_data[BEST_PARSE_RANK]
                {
#ifset DEBUG
                        if debug_flags & D_PARSE_RANK and this_parse_rank > parser_data[BEST_PARSE_RANK]
                        {
                                print "[parser_data[BEST_PARSE_RANK] = "; number this_parse_rank; "]"
                        }
#endif
                        parser_data[BEST_PARSE_RANK] = this_parse_rank
                }
        }
#ifset DEBUG
        if debug_flags & D_FINDOBJECT and not recurse
        {
                print "[FindObject("; obj.name; " ["; number obj; "], "; \
                        objloc.name; " ["; number objloc; "]):  "; \
                        "true]"
        }
#endif
        return found_result
}

!----------------------------------------------------------------------------
! ObjectIsKnown(obj)
! If it is undesirable to use the rules for disqualifying hitherto unknown
! objects from player actions, replace ObjectisKnown with a routine that
! always returns a true value.

routine ObjectIsKnown(obj)
{
        if obj is known
                return true
        return false
}

!----------------------------------------------------------------------------
! ExcludeFromAll(obj)
! If global decision rules are desired for "all" actions, replace
! ExcludeFromAll, returning true if <obj> is to be excluded.  Return 2 to
! force the INCLUSION of <obj>.

routine ExcludeFromAll(obj)
{
        if obj is hidden
                return true
        return false
}

!----------------------------------------------------------------------------
! PutInScope(object, actor)
! makes <object> accessible to <actor> (where <actor> is usually the player)
! provided that <object> has an in_scope property with an empty slot--i.e.
! one that equals 0; returns false if <object> cannot be placed in scope
! of <actor>
!
! RemoveFromScope(object, actor)
! removes <object> from the scope of <actor>

routine PutInScope(obj, act)
{
        local a

        if act = 0:  act = player
        for (a=1; a<=obj.#in_scope; a++)
        {
                if obj.in_scope #a = 0
                {
                        obj.in_scope #a = act
                        return true
                }
        }
}

routine RemoveFromScope(obj, act)
{
        local a

        for (a=1; a<=obj.#in_scope; a++)
        {
                if obj.in_scope #a = act or act = 0
                {
                        obj.in_scope #a = 0
                        return true
                }
        }
}

!----------------------------------------------------------------------------
! AssignPronoun(object)
! sets the appropriate pronoun global to <object>

routine AssignPronoun(obj)
{
#ifclear OLD_STYLE_PRONOUNS
        if obj >= it_object and obj <= them_object
                return
#endif
        if parser_data[PARSER_STATUS] & PRONOUNS_SET:  return
        if obj = player:  return

        ! No use if you can't refer to it
        if not obj.#noun and not obj.#adjective
                return

        if obj is not living
        {
                if obj is not plural
                        it_obj = obj
                else
                        them_obj = obj
        }
        else
        {
                if obj is plural
                        them_obj = obj
                elseif obj is female
                        her_obj = obj
                else
                        him_obj = obj
        }
}

!----------------------------------------------------------------------------
! PrintStatusline
! prints an appropriate statusline as specified by global STATUSTYPE

routine PrintStatusline
{
        if display.linelength < 80
                display.statusline_height = 2
        else
                display.statusline_height = 1

        Font(BOLD_OFF | ITALIC_OFF | UNDERLINE_OFF | PROP_OFF)
        window display.statusline_height
        {
                color SL_TEXTCOLOR, SL_BGCOLOR
                cls
                locate 1, 1
                if not location
                        print "\_";
                elseif not light_source
                        print "In the dark";
                else
                {
                        if FORMAT & DESCFORM_F:  print "\_";
                        print capital location.name;
                }

                if display.statusline_height = 1
                        print to 65;
                else
                {
                        locate 1, 2
                        if FORMAT & DESCFORM_F:  print "\_";
                }

                if STATUSTYPE = 1
                        print number score; " / "; number counter;
                elseif STATUSTYPE = 2
                        print HoursMinutes(counter);
        }
        color TEXTCOLOR, BGCOLOR
        Font(DEFAULT_FONT)
}

!----------------------------------------------------------------------------
! HoursMinutes(val[, military])
! prints the time in 12-hour hh:mm format, as given by <val> minutes past
! midnight, or in 24-hour hh:mm military-time format if <military> is true

routine HoursMinutes(val, military)
{
        local hours, minutes

        hours = val / 60
        minutes = val - hours * 60

        if not military
        {
                if hours > 12:     hours -= 12
                elseif hours = 0:  hours = 12
        }
        elseif hours < 10:  print "0";

        print number hours; ":";
        if minutes < 10
                print "0";
        print number minutes; " ";

        if not military
        {
                if val >= 720
                        print "p.m.";
                else
                        print "a.m.";
        }
}

!----------------------------------------------------------------------------
! The(object)                           ! prints "the <object>"
!
! When the player is in the first person, pass a second, non-false argument
! to generate "me" instead of "I".

routine The(obj, a)
{
        AssignPronoun(obj)

        if obj = player and player_person = 1 and a
        {
                print player.pronoun #2;
                return
        }

        if obj.article
                print "the ";
        print obj.name;
}

!----------------------------------------------------------------------------
! CThe(object)                          ! prints "The <object>"

routine CThe(obj)
{
        AssignPronoun(obj)

        if obj.article
                print "The "; obj.name;
        else
                print capital obj.name;
}

!----------------------------------------------------------------------------
! Art(object)

routine Art(obj, a)                     ! prints, for example, "an <object>"
{
        AssignPronoun(obj)

        if obj = player and player_person = 1 and a
        {
                print player.pronoun #2;
                return
        }

        if obj.article
                print obj.article; " ";
        print obj.name;
}

!----------------------------------------------------------------------------
! CArt(object)                          ! prints, for example, "An <object>"

routine CArt(obj)
{
        AssignPronoun(obj)

        if obj.article
                print capital obj.article; " "; obj.name;
        else
                print capital obj.name;
}

!----------------------------------------------------------------------------
! IsorAre(object, [optional parameter])
! prints "is" or "are" (or "'s" or "'re") to agree with <object>
!
! IsorAre(object, true)
! forces use of "is" and "are" instead of "'s" and "'re"

routine IsorAre(obj, a)
{
        if obj is plural
        {
                ! Assuming a first-person player object is 'plural'
                if obj = player and player_person = 1
                {
                        if a:  print " am";
                        else:  print "'m";
                }
                else
                {
                        if player_person = 3:  a = true
                        if a:  print " are";
                        else:  print "'re";
                }
        }
        else
        {
                if a:  print " is";
                else:  print "'s";
        }
}

!----------------------------------------------------------------------------
! MatchSubject(object)
! conjugates a present-tense verb to agree with <object>

routine MatchSubject(obj)
{
        if obj is not plural
                print "s";
}

!----------------------------------------------------------------------------
! MatchPlural(object, word1, word2)
! prints <word1> if <object> is singular or <word2> if <object> is plural

routine MatchPlural(obj, word1, word2)
{
        print " ";
        if obj is not plural
                print word1;
        else
                print word2;
}

!----------------------------------------------------------------------------
! NumberWord(number)
! prints a number in non-numerical word format, where <number> is between
! -32768 to 32767
!
! NumberWord(number, true)
! prints the word beginning with a capital letter if a second (true)
! argument is provided

routine NumberWord(n, cap)
{
        local remaining, place, printed_tens

        if n = 0
        {
                if cap:  print capital DigitWord(n);
                else:  print DigitWord(n);
                return
        }
        if n < 0
        {
                if cap:  print "Minus ";
                else:  print "minus ";
                n = -n
                cap = 0
        }

        place = 1000
        while n
        {
                if n >= place
                {
                        if remaining
                        {
                                if place = 100
                                        print ", ";
                                elseif place = 10
                                        print " "; AND_WORD; " ";
                                elseif place = 1
                                {
                                        if printed_tens
                                                print "-";
                                        else
                                                print " "; AND_WORD; " ";
                                }
                        }

                        if place >= 100
                        {
                                if cap:  NumberWord(n/place, true)
                                else:  NumberWord(n/place)
                                print " "; DigitWord(place);
                                n = n-n/place*place
                        }
                        elseif place = 10 and (n >= 20)
                        {
                                if cap:  print capital DigitWord(n/10*10);
                                else:  print DigitWord(n/10*10);
                                n = n-n/place*place
                                printed_tens = true
                        }
                        else
                        {
                                if cap:  print capital DigitWord(n);
                                else:  print DigitWord(n);
                                n = 0
                        }
                        cap = 0
                        remaining = true
                }
                place = place/10
        }
}

routine DigitWord(n)
{
        select n
        case 0:         return "zero"
        case 1:         return "one"
        case 2:         return "two"
        case 3:         return "three"
        case 4:         return "four"
        case 5:         return "five"
        case 6:         return "six"
        case 7:         return "seven"
        case 8:         return "eight"
        case 9:         return "nine"
        case 10:        return "ten"
        case 11:        return "eleven"
        case 12:        return "twelve"
        case 13:        return "thirteen"
        case 14:        return "fourteen"
        case 15:        return "fifteen"
        case 16:        return "sixteen"
        case 17:        return "seventeen"
        case 18:        return "eighteen"
        case 19:        return "nineteen"
        case 20:        return "twenty"
        case 30:        return "thirty"
        case 40:        return "forty"
        case 50:        return "fifty"
        case 60:        return "sixty"
        case 70:        return "seventy"
        case 80:        return "eighty"
        case 90:        return "ninety"
        case 100:       return "hundred"
        case 1000:      return "thousand"
}


!----------------------------------------------------------------------------
! StringToNumber(word)
! returns the numerical value of a word such as "100"; note that it returns
! 0 for any non-number, not just "0"

routine StringToNumber(w)
{
        local len, val, n, factor = 1
        len = string(_temp_string, w, 255)

        local i
        for (i=len-1; i>=0; i--)
        {
                n = _temp_string[i]
                if n >= '0' and n <= '9'
                {
                        n -= '0'
                        val += (n*factor)
                }
                elseif i = 0 and n = '-'
                {
                        val = -val
                }
                else
                        return 0

                factor *= 10
        }
        return val
}


!----------------------------------------------------------------------------
! Indent
! indents only if the NOINDENT_F bit is not set in the FORMAT mask; returns
! the null word "" (0 or false); if <newl> is true, a newline is printed
! first (if appropriate)

routine Indent(newl)
{
        local i

        if override_indent or display.cursor_column > 1
                print AFTER_PERIOD;
        elseif not (FORMAT & NOINDENT_F) and INDENT_SIZE
        {
                ! See display.cursor_column > 1, above
                !print newline

                if newl
                        print ""
                print "\_";
                for (i=2; i<=INDENT_SIZE; i++)
                        print " ";
        }
        override_indent = false
}

!----------------------------------------------------------------------------
! DescribePlace(location, [optional parameter])
! prints the location name, followed by the location description, if
! required
!
! DescribePlace(location, true)
! forces a location description

routine Describeplace(place, long)
{
        local obj, count, notlisted, tempformat

        parser_data[PARSER_STATUS] &= ~PRONOUNS_SET

        ! Since, for example, a room description following entering via
        ! DoGo does not trigger before/after properties tied to looking
        ! around:
        !
#ifclear NO_VERBS
        if verbroutine ~= &DoLookAround
        {
                if place is not visited and verbosity ~= 1
                        return Perform(&DoLookAround)
                elseif long = true or verbosity = 2
                        return Perform(&DoLookAround)
        }
#endif

        if not light_source
        {
                Message(&DescribePlace, 1)     ! "It's too dark to see..."
                return
        }

        place is known

        ! Print the name of the location as a heading
        Font(BOLD_ON)
        print "\n"; capital place.name;

        ! Print ", in <something>" if necessary
        if location = place and player not in place
        {
                if parent(player).prep
                        print ", "; parent(player).prep; " ";
                elseif parent(player) is platform
                        print ", "; ON_WORD; " ";
                else
                        print ", "; IN_WORD; " ";
                print Art(parent(player))
        }
        print newline

        Font(BOLD_OFF)
        override_indent = false

        if place is not visited and verbosity ~= 1
        {
                if &place.initial_desc or &place.long_desc
                        Indent
                if not place.initial_desc
                        run place.long_desc
        }
        elseif long = true or verbosity = 2
        {
                if &place.long_desc
                        Indent
                run place.long_desc
        }

        if &place.list_contents and FORMAT & DESCFORM_F
                print ""        ! for double-space-after-heading formatting

        ! A location may contain an overriding listing routine, as may any
        ! parent, in the list_contents property
        !
        if not place.list_contents
        {
                list_nest = 0

                ! For double-space-after-heading formatting:
                if FORMAT & DESCFORM_F
                {
                        for obj in place
                        {
                                if obj is not hidden and
                                        (player not in obj or children(obj) > 1)
                                {
                                        print ""
                                        break
                                }
                        }
                }

                ! List contents of chair, vehicle, etc. player is in
                if player not in location
                {
                        list_nest = 1
                        WhatsIn(Parent(player))
                }

                ! List all characters, if any
                count = 0
                for obj in place
                {
                        if obj is hidden or obj is not living or
                                player in obj
                        {
                                obj is already_listed
                        }
                        else
                        {
                                obj is not already_listed
                        }
                }
                for obj in place
                {
                        if obj is not already_listed
                        {
                                print newline
                                ShortDescribe(obj)
                                if obj is not already_listed
                                        count++
                        }
                }

                list_count = count
                count = 0

                if list_count           ! if characters are to be listed
                {
                        tempformat = FORMAT
                        FORMAT = FORMAT | FIRSTCAPITAL_F | ISORAREHERE_F
                        FORMAT = FORMAT | USECHARNAMES_F
                        if FORMAT & LIST_F
                        {
                                FORMAT = FORMAT & ~LIST_F       ! clear it
                                FORMAT = FORMAT | TEMPLIST_F
                        }
                        Indent
                        list_nest = 0
                        ListObjects(place)
                        FORMAT = tempformat
                }

                for obj in place
                {
#ifset USE_ATTACHABLES
                        ! Exclude all attachables for now (and characters)

                        if obj is living or obj.type = attachable or
                                player in obj
#else
                        if obj is living or player in obj
#endif
                                obj is already_listed
                        else
                                obj is not already_listed
                }

                for obj in place
                {
#ifset USE_PLURAL_OBJECTS
                        ! ...And don't list identical objects yet, either

                        if (obj.identical_to).type = identical_class
                        {
                                if obj is not hidden
                                        count++
                        }
                        elseif player not in obj
#else
                        if player not in obj
#endif
                        {
                                if obj is not already_listed and
                                        obj is not hidden
                                {
                                        ShortDescribe(obj)
                                        if obj is not already_listed
                                                notlisted++
                                }
                        }
                }

                if notlisted or count
                {
                        list_count = notlisted + count
                        tempformat = FORMAT
                        FORMAT = FORMAT | FIRSTCAPITAL_F | ISORAREHERE_F
                        if FORMAT & LIST_F
                        {
                                FORMAT = FORMAT & ~LIST_F       ! clear it
                                FORMAT = FORMAT | TEMPLIST_F
                        }
                        Indent
                        list_nest = 0
                        ListObjects(place)
                        FORMAT = tempformat
                }

#ifclear NO_OBJLIB
#ifset USE_ATTACHABLES
                for obj in place
                {
                        ! Print attachables last
                        if obj.type = attachable and obj is not hidden
                        {
                                ShortDescribe(obj)
                                if obj is not already_listed
                                        Message(&DescribePlace, 2, obj)
                        }
                }
#endif

                print newline
                override_indent = false

                ! Finally, list contents of scenery objects (unless we've
                ! already done so as the parent of the player)
                !
                for obj in place
                {
                        if obj.type = scenery
                        {
                                obj is known
                                if player not in obj and
                                        (obj is open or obj is not openable)
                                {
                                        list_nest = 1
                                        WhatsIn(obj)
                                }
                        }

                        ! For scenery-derived objects that may change the type
                        elseif obj is static, hidden
                                obj is known
                }
#endif  ! ifclear NO_OBJLIB

                print newline
                need_newline = false

        }
}

!----------------------------------------------------------------------------
! ShortDescribe(object)
! prints the initial description of <object> if not moved (if it has one),
! or the when_open or when_closed message, if applicable, or the short
! description if moved (if it has one).

routine ShortDescribe(obj)
{
        obj is known

        if list_nest = 1
                print newline

        AssignPronoun(obj)

        if obj is not moved and &obj.initial_desc
        {
                Indent
                run obj.initial_desc
                jump CheckContents
        }

        if obj is openable
        {
                if obj is open
                {
                        if &obj.when_open
                        {
                                Indent
                                run obj.when_open
                                jump CheckContents
                        }
                }
                elseif &obj.when_closed
                {
                        Indent
                        run obj.when_closed
                        jump CheckContents
                }
        }

        if &obj.short_desc
                Indent

        if not obj.short_desc
                return

:CheckContents

        obj is already_listed
        AssignPronoun(obj)

        list_count = 0
        if children(obj) > 0 and (obj is not container or
                (obj is container and obj is not openable) or
                (obj is container and obj is openable and
                        (obj is open or obj is transparent))) and
                obj is not quiet
        {
                list_nest = 1
                WhatsIn(obj)
        }

        ! If INDENT_SIZE is 0, formatting may be thrown off when listing
        ! the contents of an object:
        if INDENT_SIZE = 0:  need_newline = true

        if need_newline:  print newline
}

!----------------------------------------------------------------------------
! WhatsIn(object)
! lists the children of <object>, if any, in a relatively orderly manner

routine WhatsIn(obj)
{
        local i, totallisted
        local initial_list_nest

        if FORMAT & NORECURSE_F
                return

        for i in obj
        {
                i is not already_listed
                if i is not hidden
                        totallisted++
        }

        if totallisted = 0
                return

        list_count = totallisted

        if obj is not container or (obj is container and obj is platform) or
                (obj is container and (obj is not openable or
                        (obj is openable and
                                (obj is open or obj is transparent)))) and
                (obj ~= player or FORMAT & INVENTORY_F) and obj is not quiet
        {
                SpecialDesc(obj)

                ! If list_count is 0 now, but totallisted was not, something must have been
                ! printed by SpecialDesc

                if list_count = 0
                {
                        if FORMAT & INVENTORY_F and not (FORMAT & LIST_F) and
                                list_nest = 0
                        {
                                print ""
                        }
                        return totallisted
                }

                if obj.list_contents
                        return totallisted

                initial_list_nest = list_nest

                if FORMAT & LIST_F
                {
                        if list_nest
                        {
                                ! Indent the first time so that it lines up with
                                ! paragraph indentation:
                                i = list_nest
                                if list_nest = 1 and not (FORMAT & NOINDENT_F)
                                {
                                        Indent
                                        i--
                                }

                                print to (i * 2);       ! INDENT_SIZE);
                        }
                }
                else
                {
                        Indent
                }

                if obj.contains_desc    ! custom heading
                {
                        if FORMAT & LIST_F
                                print ":"
                }
                else
                {
                        if obj = player
                        {
                                if FORMAT & LIST_F and list_count < totallisted
                                        print "\n";

                                ! "You are carrying..."
                                Message(&WhatsIn, 1, totallisted)

                                if FORMAT & LIST_F
                                        print ":"
                        }
                        elseif obj is living and not obj.prep
                        {
                                ! "X has..."
                                Message(&WhatsIn, 2, obj, totallisted)
                                if FORMAT & LIST_F
                                        print ":"
                        }
                        else
                        {
                                if list_count < totallisted
                                        ! "Also sitting on/in..."
                                        Message(&Whatsin, 3, obj)
                                else
                                        ! "Sitting on/in..."
                                        Message(&Whatsin, 4, obj)
                                The(obj)
                                FORMAT = FORMAT | ISORARE_F
                        }
                }

                ListObjects(obj)

                list_nest = initial_list_nest
        }
        return totallisted
}

!----------------------------------------------------------------------------
! SpecialDesc(object)
! checks the children of <object> and runs any applicable preliminary
! descriptions; returns the total number of remaining (i.e. non-listed)
! objects in the list_count global variable

routine SpecialDesc(obj)
{
        local a, c, flag, printed_blankline

        if FORMAT & LIST_F
                return

        list_count = 0
        for a in obj
        {
                if a is not hidden
                {
                        c++
                        flag = true
                }
                else
                        flag = false

                if FORMAT & INVENTORY_F and obj = player and flag
                {
                        if &a.inv_desc
                                Indent
                        if a.inv_desc
                        {
                                if FORMAT & LIST_F:  print newline
                                AddSpecialDesc(a)
                        }
                }

                elseif a is not moved and flag
                {
                        if &a.initial_desc
                        {
                                print newline
                                override_indent = false
                                if FORMAT & INVENTORY_F and FORMAT & NOINDENT_F and not printed_blankline
                                        print ""
                                printed_blankline = true
                                Indent
                        }
                        if a.initial_desc
                                AddSpecialDesc(a)
                }
        }
        list_count = c - list_count
}

routine AddSpecialDesc(a)
{
        a is already_listed
        a is known
        list_count++
        AssignPronoun(a)
}

!----------------------------------------------------------------------------
! ListObjects(object)
! lists all the objects in <object>, providing that the list_count global
! contains the total number of objects to be listed.

routine ListObjects(thisobj)
{
        local i, obj, count, pluralcount
        local templist_count            ! temporary total of unlisted objs.
        local id_count                  ! for identical (or plural) objects
#ifset USE_PLURAL_OBJECTS
        local j, this_class
#endif

        list_nest++
        for obj in thisobj
        {
                if obj is hidden
                {
                        obj is already_listed
#ifclear NO_OBJLIB
                        if obj.type = scenery
                                obj is known
#endif
                }
                else
                        obj is known

#ifset USE_PLURAL_OBJECTS

                ! Need to count identical (and possibly plural) objects
                ! for grouping in listing

                if obj.identical_to and obj is not already_listed
                {
                        this_class = obj.identical_to
                        if this_class.type = identical_class or
                                FORMAT & GROUPPLURALS_F
                        {
                                id_count = 1
                                for (i=1; i<=this_class.#plural_of; i++)
                                {
                                        j = this_class.plural_of #i
                                        if j in thisobj and j~=obj and j is not hidden
                                        {
                                                id_count++
                                                pluralcount++
                                                list_count--
                                                j is already_listed
                                        }
                                }
                        }
                }
#endif
                if obj is not already_listed
                {
                        ! May have a leading "is" or "are" that needs to
                        ! be printed at the head of the list

                        if FORMAT & ISORARE_F
                        {
                                if list_count = 1 and id_count <= 1 and
                                        obj is not plural
                                {
                                        print " "; IS_WORD;
                                }
                                else
                                {
                                        print " "; ARE_WORD;
                                }
                                if FORMAT & LIST_F
                                        print ":"
                                FORMAT = FORMAT & ~ISORARE_F    ! clear it
                        }

                        need_newline = false
                        if obj is plural
                                pluralcount++

                        AssignPronoun(obj)
                        if not (FORMAT & LIST_F)
                        {
                                if list_count > 2 and count
                                        print ",";
                                if list_count > 1 and count = list_count - 1
                                        print " "; AND_WORD;
                                if not (FORMAT & FIRSTCAPITAL_F)
                                        print " ";
                        }
                        else
                        {
                                print to (list_nest * 2);       ! INDENT_SIZE);
                        }

#ifset USE_PLURAL_OBJECTS

                        ! If a number of identical (or possibly plural)
                        ! objects are grouped together, they are printed
                        ! as a single entry in the list
                        !
                        if obj.identical_to and
                                (this_class.type = identical_class or
                                FORMAT & GROUPPLURALS_F)
                        {
                                if id_count = 1
                                {
                                        if FORMAT & FIRSTCAPITAL_F
                                                CArt(obj)
                                        else
                                                Art(obj)
                                }
                                else
                                {
                                        if FORMAT & FIRSTCAPITAL_F
                                                print NumberWord(id_count, true);
                                        else
                                                print NumberWord(id_count);
                                        print " "; this_class.name;

                                        if this_class.type = plural_class
                                        {
                                                local k

                                                if FORMAT & LIST_F
                                                        print ":";
                                                else
                                                        print " (";

                                                k = 0
                                                for (i=1; i<=this_class.#plural_of; i++)
                                                {
                                                        j = this_class.plural_of #i
                                                        if parent(j) = thisobj
                                                        {
                                                                if not (FORMAT & LIST_F)
                                                                {
                                                                        if id_count > 2 and k
                                                                                print ",";
                                                                        if k = id_count - 1
                                                                                print " "; AND_WORD;
                                                                        if k
                                                                                print " ";
                                                                }
                                                                else
                                                                {
                                                                        print "\n";
                                                                        print to ((list_nest+1) * 2);   ! INDENT_SIZE);
                                                                }
                                                                Art(j)
                                                                if not (FORMAT & NOPARENTHESES_F)
                                                                        ObjectIs(j)
                                                                k++
                                                        }
                                                }
                                                if not (FORMAT & LIST_F):  print ")";
                                        }
                                }
                        }
                        else
                        {
#endif
                                ! Regular old non-plural, non-identical
                                ! objects get listed here:

                                if FORMAT & FIRSTCAPITAL_F
                                        CArt(obj)
                                else:  Art(obj)
                                if not (FORMAT & NOPARENTHESES_F)
                                        ObjectIs(obj)
#ifset USE_PLURAL_OBJECTS
                        }
#endif
                        FORMAT = FORMAT & ~FIRSTCAPITAL_F       ! clear it

                        count++
                }

                ! For itemized listings, list the children of
                ! each object immediately after that object (unless
                ! it is a SpecialDesc-printed description)

                if obj is not hidden and FORMAT & LIST_F
                {
                        print newline
                        if children(obj)
                        {
                                if not obj.list_contents
                                {
                                        templist_count = list_count
                                        WhatsIn(obj)
                                        list_count = templist_count
                                }
                        }
                }
        }

        ! If not an itemized list, it is necessary to finish off the
        ! sentence, adding any necessary words at the end.  Then, the
        ! children of all previously objects listed at this level are
        ! listed.

        if not (FORMAT & LIST_F)
        {
                if count
                {
                        if list_nest = 1 and FORMAT & ISORAREHERE_F
                        {
                                if count + pluralcount > 1
                                        print " "; ARE_WORD;
                                else:  print " "; IS_WORD;
                                print " "; HERE_WORD;
                                FORMAT = FORMAT & ~ISORAREHERE_F  ! clear it

                                if not (FORMAT&LIST_F or FORMAT&TEMPLIST_F)
                                        override_indent = true
                        }

                        if not (FORMAT & NORECURSE_F)
                                print ".";
                }

                i = 0

                for obj in thisobj
                {
                        if children(obj) and obj is not hidden and
                                (obj is not already_listed or
                                        thisobj ~= location)
                        {
                                if FORMAT & TEMPLIST_F
                                {
                                        FORMAT = FORMAT | LIST_F & ~TEMPLIST_F
                                        i = true
                                        print newline
                                }

                                templist_count = list_count
                                WhatsIn(obj)
                                list_count = templist_count
                        }
                }
        }

        if --list_nest = 0
        {
                if not (FORMAT & LIST_F) and not (FORMAT & NORECURSE_F)
                {
                        print newline
                        override_indent = false
                        need_newline = false
                }
        }
}

!----------------------------------------------------------------------------
! PropertyList(object, property[, article])
! lists all the objects in <object>.<property>, returning the number of
! objects printed; if <article> is false or omitted, the indefinite article
! is used

routine PropertyList(obj, prop, artic)
{
        local a, b, n, total

        for (a=1; a<=obj.#prop; a++)
        {
                if obj.prop #a:  total++
        }

        for (a=1; a<=obj.#prop; a++)
        {
                b = obj.prop #a
                if b
                {
                        if artic
                                The(b)
                        else
                                Art(b)

                        if a < total and total > 2
                                print ", ";
                        elseif a = total - 1:  print " ";

                        if a = total - 1
                                print AND_WORD; " ";
                        n++
                }
        }
        return n
}

!----------------------------------------------------------------------------
! MovePlayer(location[, silent])
! moves the player to the object <location>, with no description if <silent>
! is true
!
! MovePlayer(direction[, silent[, ignore]])
! moves player in <direction>, where <direction> is a direction object.
! If <ignore> is true, before/after routines relating to the move are
! not checked.
!
! MovePlayer calls DarkWarning when there is no light source in the new
! location; replace it with a new DarkWarning routine for a more elaborate
! response, such as the possible demise of the player

routine MovePlayer(loc, silent, ignore)
{
        local v, obj, xobj, act, ret

#ifclear NO_OBJLIB
        if loc.type = direction
        {
                local l
                l = location.(loc.dir_to)
                if l > 1                ! since a message always returns 1
                        loc = l
                else
                        return
        }
#endif

#ifset USE_ATTACHABLES
        if ObjectisAttached(player, location, loc)
                return
#endif

        ! Check if there's a before routine for MovePlayer in the new
        ! location.  Note that the (potential) new location and the old
        ! location are stored in object and xobject, respectively.
        !
        v = verbroutine
        obj = object
        xobj = xobject
        act = actor
        verbroutine = &MovePlayer
        object = loc
        xobject = location
        actor = player
        if not ignore
        {
                ret = player.before
                if ret:  jump LeaveMovePlayer
                ret = location.before
                if ret:  jump LeaveMovePlayer
                ret = loc.before
                if ret:  jump LeaveMovePlayer
        }

        move player to loc
        old_location = location
        if parent(loc) = 0              ! if it's likely a room object
                location = loc
        else                            ! if it's an enterable object
                location = parent(loc)  ! (noting that the object must be
                                        ! in a room, not inside another
                                        ! non-room object)

#ifset USE_ATTACHABLES
        MoveAllAttachables(player, old_location, location)
#endif

        PrintStatusline

:LeaveMovePlayer

        if not ret
        {
                if not FindLight(location)
                        DarkWarning
                elseif not silent
                {
                        DescribePlace(location)
                        event_flag = true
                        location is visited
                }

        ! Check if there's an after routine for MovePlayer in the new
        ! location:
        !
                if not ignore
                {
                        ret = player.after
                        if not ret
                                ret = location.after
                }
        }

        verbroutine = v
        object = obj
        xobject = xobj
        actor = act

        return ret
}

routine DarkWarning
{
        print CThe(player); " stumble"; MatchSubject(player); \
                " around in the dark."
}

!----------------------------------------------------------------------------
! FindLight(object)
! returns the object number of light_source if any light is visible from
! within <object> (where <object> is usually a location)
!
! ObjectisLight is called by FindLight

routine FindLight(loc)
{
        light_source = 0

        if loc is light
        {
                light_source = loc
                return light_source
        }
        elseif ObjectisLight(player)
                return light_source
        return ObjectisLight(loc)
}

routine ObjectisLight(obj)
{
        local nextobj

        if obj is light
        {
                light_source = obj
                return light_source
        }
        if obj is not container or
                (obj is container and obj is not openable) or
                (obj is container and obj is openable and
                        (obj is open or obj is transparent))
        {
                for nextobj in obj
                {
                        if ObjectisLight(nextobj)
                                return light_source
                }
        }
}

!----------------------------------------------------------------------------
! ObjectIs(object)
! prints a list of parenthetical attributes

routine ObjectIs(obj)
{
        local n

        if obj is clothing:  n = TestObjectIs(obj, worn, "being worn", n)
        n = TestObjectIs(obj, light, "providing light", n)

        if n:  print ")";

        run obj.desc_detail
}

routine TestObjectIs(obj, attr, str, n)
{
        if obj is attr
        {
                if n = 0
                        print " (";
                else
                        print " "; AND_WORD;
                print str;
                n++
        }
        return n
}

!----------------------------------------------------------------------------
! Acquire(object 1, object 2)
! moves <object 2> to <object 1>; returns true if successful

routine Acquire(newparent, newchild)
{
        local p

        CalculateHolding(newparent)

        if newparent.holding + newchild.size > newparent.capacity
                return false
        else
        {
                p = parent(newchild)
                move newchild to newparent
                CalculateHolding(p)
                newchild is moved
                newchild is not hidden
                newparent.holding = newparent.holding + newchild.size
                return true
        }
}

!----------------------------------------------------------------------------
! CalculateHolding(object)
! recalculates the correct holding property for an object; used before
! adding or subtracting children

routine CalculateHolding(obj)
{
        local i

        obj.holding = 0
        for i in obj
        {
                if i is not worn or obj ~= player
                        obj.holding = obj.holding + i.size
        }
}

!----------------------------------------------------------------------------
! Contains(object 1, object 2)
! returns <object2> if <object 1> contains <object 2> (even as a grandchild)

routine Contains(obj, possible_child)
{
        local nextobj

        for (nextobj=parent(possible_child); nextobj; nextobj=parent(nextobj))
        {
                if nextobj = obj
                        return possible_child
        }
}

!----------------------------------------------------------------------------
! CheckReach(object)
! returns true if either player object's current parent has no reach
! property specified, or if <object> is in the list of reachable objects

routine CheckReach(obj)
{
        local i

        if not obj or obj = parent(player)
                return true

#ifclear NO_VERBS
        if (verbroutine ~= &DoLook, &DoLookIn) and parent(object) and
                parent(object) ~= player and
                parent(object) is transparent and parent(object) is not open and
                parent(object) is not living
        {
                VMessage(&DoGet, 5)     ! "X is closed."
                return false
        }
#endif

        if not parent(player).reach or Contains(parent(player), obj)
                return true

#ifclear NO_VERBS
        if parent(obj) is living
        {
                if verbroutine ~= &DoGet, &DoLook

                        ! "Except that X has it..."
                        Message(&CheckReach, 1, obj)

                elseif verbroutine = &DoGet and parent(obj) is unfriendly

                        ! "Except that X doesn't want to give it to you..."
                        Message(&CheckReach, 2, obj)
        }
#endif

        for (i=1; i<=parent(player).#reach; i++)
        {
                if Contains(parent(player).reach #i, obj) or
                        obj = parent(player).reach #i
                {
                        return true
                }
        }

#ifset USE_ATTACHABLES
        if parent(player).type = attachable
        {
                if InList(parent(player), attached_to, obj)
                        return true
        }
        if obj.type = attachable
        {
                if InList(obj, attached_to, parent(player))
                        return true
        }
#endif

        ! "You can't reach it..."
        Message(&CheckReach, 3, obj)
}

!----------------------------------------------------------------------------
! GetInput
! receives input from the keyboard, parsing into the word[] array; unknown
! words--i.e. those that aren't in the dictionary--are equated to the null
! string ("")
!
! GetInput(prompt)
! where the optional <prompt> represents a dictionary word, prints <prompt>
! before receiving input

routine GetInput(p)
{
        print p;
        input
}

!----------------------------------------------------------------------------
! YesorNo
! returns true if word[1] is "yes", false if "no"; prompts for a
! new input if neither

routine YesorNo
{
        local w, count
        w = word[1]
        while true
        {
                if w = "yes", "y"
                        return true
                elseif w = "no", "n"
                        return false

                if ++count < 10
                        Message(&YesorNo, 1)    ! ask "yes" or "no"
                else
                        Message(&YesorNo, 2)
                GetInput
                w = word[1]
        }
}

!----------------------------------------------------------------------------
! Font(style mask)
! changes the font style based on the style(s) specified in <style mask>,
! which may consist of one or more font bitmask constants combined with
! the "+" or "|" operator:
!
!       Font(BOLD_ON | ITALIC_OFF | ...)

routine Font(mask)
{
#ifclear NO_FONTS
        if mask & BOLD_ON:        print "\B";
        if mask & BOLD_OFF:       print "\b";
        if mask & ITALIC_ON:      print "\I";
        if mask & ITALIC_OFF:     print "\i";
        if mask & UNDERLINE_ON:   print "\U";
        if mask & UNDERLINE_OFF:  print "\u";
        if mask & PROP_ON:        print "\P";
        if mask & PROP_OFF:       print "\p";
#endif
}


!----------------------------------------------------------------------------
! AUXILIARY MATH ROUTINES:
!
! Function:     Returns:
!
! abs(a)        the absolute value of <a>
! higher(a, b)  the greater of <a> or <b>
! lower(a, b)   the lower of <a> or <b>
! mod(a, b)     the remainder of <a> divided by <b>
! pow(a, b)     <a> to the power of <b>

#ifclear NO_AUX_MATH

routine abs(a)
{
        if a < 0
                return -a
        return a
}

routine higher(a, b)
{
        if a > b:  return a
        return b
}

routine lower(a, b)
{
        if a < b:  return a
        return b
}

routine mod(a, b)
{
        return a-(a/b*b)
}

routine pow(a, b)
{
        local i, n

        if b = 0:  return 1
        if b < 0:  return 0
        n = a
        for (i=2; i<=b; i++)
                n = n * a
        return n
}

#endif  ! ifclear NO_AUX_MATH

!----------------------------------------------------------------------------
! STRING ARRAY ROUTINES:
!
! StringCompare(array1, array2)
! returns 1 if <array1> is lexically greater than <array2>, -1 if <array1>
! is lexically less than <array2>, and 0 if the two string arrays are
! identical
!
! StringCopy(new, old)
! StringCopy(new, old, length)
! either copies the array beginning at <old> to <new>, to a maximum of
! <length> characters, if specified
!
! StringDictCompare(array, dictentry)
! for comparing a string array with a dictionary entry; return values are
! as for StringCompare
!
! StringEqual(array1, array2)
! returns true if the two strings are identical
!
! StringLength(array)
! returns the number of characters in string <array>
!
! StringPrint(array)
! StringPrint(array, start, end)
! either prints the string stored in <array>, beginning and ending with
! <start> and <end>, if specified

#ifclear NO_STRING_ARRAYS

#if undefined _temp_string
array _temp_string[256]                 ! maximum string length is 255 char.
#endif

routine StringCompare(a, b)
{
        local i, alen

        alen = StringLength(a)

        for (i=0; i<alen; i++)
        {
                if array a[i] > array b[i]:     return  1
                elseif array a[i] < array b[i]: return -1
        }
        if array b[i] ~= 0:  return -1
}

routine StringCopy(new, old, len)
{
        local i

        if len = 0
                len = StringLength(old)

        for (i=0; i<len; i++)
                array new[i] = array old[i]
        array new[len] = 0
}

routine StringDictCompare(a, d)
{
        string(_temp_string, d, 255)
        return StringCompare(a, _temp_string)
}

routine StringEqual(a, b)
{
        return not StringCompare(a, b)
}

routine StringLength(arr)
{
        local i
        i = 0
        while array arr[i] ~= 0:  i++
        return i
}

routine StringPrint(a, start, end)
{
        local i

        if end = 0
                end = StringLength(a)
        for (i=start; i<end; i++)
        {
                if array a[i] = 0
                        break
                printchar array a[i]
        }
}

#endif  ! ifclear NO_STRING_ARRAYS

!----------------------------------------------------------------------------
! Menu(number, [width][, selection]])
!
! The Menu routine expects the array menuitem[] to hold a series of
! dictionary entries representing the list of possible choices, with the
! title of the menu contained in menuitem[0].  It returns the number chosen,
! or 0 if none is selected.
!
! The argument <number> gives the number of menu items, and the optional
! <width> gives the width of the menu, in characters.  If no width is
! specified, it defaults to the greater of 20 or the longest menu choice.
! If <selection> is specified, it gives the starting selection in the menu.

#ifclear NO_MENUS

#if undefined _temp_string
array _temp_string[256]
#endif

constant MAX_MENUITEMS 16               ! up to 15 items (plus title)
array menuitem[MAX_MENUITEMS]

global MENU_TEXTCOLOR
global MENU_BGCOLOR
global MENU_SELECTCOLOR
global MENU_SELECTBGCOLOR

routine Menu(num, width, selection)
{
        local i, column, oldselection

        Font(BOLD_OFF | ITALIC_OFF | UNDERLINE_OFF | PROP_OFF)

        if MENU_TEXTCOLOR=0 and MENU_BGCOLOR=0  ! must not have been set
        {
                MENU_TEXTCOLOR = TEXTCOLOR
                MENU_BGCOLOR = BGCOLOR
                MENU_SELECTCOLOR = SL_TEXTCOLOR
                MENU_SELECTBGCOLOR = SL_BGCOLOR
        }

        if width = 0:  width = 20
        for (i=1; i<=num; i++)          ! determine appropriate width
#ifclear NO_AUX_MATH
                width = higher(width, string(_temp_string, menuitem[i]))
#else
        {
                local n
                n = string(_temp_string, menuitem[i])
                if n > width:  width = n
        }
#endif

        if width > display.linelength-1:  width = display.linelength-1

        ! Default selection is 1 if not otherwise given
        if selection = 0:  selection = 1
        if selection > num:  selection = num

        column = display.linelength/2 - width/2

        CenterTitle(menuitem[0])        ! print title of menu

        color MENU_TEXTCOLOR, MENU_BGCOLOR
        Font(BOLD_OFF | ITALIC_OFF | UNDERLINE_OFF | PROP_OFF)
        Message(&Menu, 1)               ! print key commands

        for (i=1; i<=num; i++)          ! print menu choices
        {
                color MENU_TEXTCOLOR, MENU_BGCOLOR
                locate column, (3+i)
                print menuitem[i]; to (column+width)
        }
        color TEXTCOLOR, BGCOLOR

        while true                      ! continuous loop
        {
                if selection ~= oldselection
                {
                        if oldselection ~= 0
                        {
                                locate column, (3 + oldselection)
                                color MENU_TEXTCOLOR, MENU_BGCOLOR
                                print menuitem[oldselection]; to (column+width)
                        }
                        color MENU_SELECTCOLOR, MENU_SELECTBGCOLOR
                        locate column, (3 + selection)
                        print menuitem[selection]; to (column+width)
                        color TEXTCOLOR, BGCOLOR
                }
                locate (column+width), (3 + selection)
                oldselection = selection
                pause
                select word[0]
                case 'N', 'n', DOWN_ARROW, RIGHT_ARROW
                {
                        if menuitem[++selection] = ""
                                ++selection
                        if selection > num:  selection = 1
                }
                case 'P', 'p', UP_ARROW, LEFT_ARROW
                {
                        if menuitem[--selection] = ""
                                --selection

                        if selection = 0:  selection = num
                }
                case 'Q', 'q', ESCAPE_KEY
                {
                        window 1:  cls
                        Font(DEFAULT_FONT)
                        return 0
                }
                case ENTER_KEY
                {
                        window 1:  cls
                        Font(DEFAULT_FONT)
                        return selection
                }

                if word[0] >= '0' and word[0] <= '9'
                {
                        i = word[0] - '0'
                        if i = 0:  i = 10

                        selection = 1
                        while --i
                        {
                                selection++
                                if menuitem[selection] = ""
                                        selection++
                        }
                        if selection > num or menuitem[selection] = ""
                                selection = oldselection
                }
        }
}

routine CenterTitle(a, lines)
{
        local l

        if lines = 0:  lines = 1

        if MENU_SELECTCOLOR = 0 and MENU_SELECTBGCOLOR = 0  ! not set yet
        {
                MENU_SELECTCOLOR = SL_TEXTCOLOR
                MENU_SELECTBGCOLOR = SL_BGCOLOR
        }

        Font(PROP_OFF)
        l = string(_temp_string, a)
        window 0                        ! remove previous window
        window lines
        {
                color MENU_SELECTCOLOR, MENU_SELECTBGCOLOR
                cls
                locate (display.linelength/2 - l/2), 1
                print a;
        }
        color TEXTCOLOR, BGCOLOR
        FONT(DEFAULT_FONT)
        cls
        locate 1, 1
}

#endif  ! ifclear NO_MENUS

!\
*****************************************************************************

FUSE AND DAEMON CLASSES AND ROUTINES

*****************************************************************************
\!

#ifclear NO_FUSES

property timer alias n_to               ! for fuses only
property tick alias ne_to               !

property activate_event alias when_open
property deactivate_event alias when_closed

class fuse
{
        type fuse
        size 0
        timer 0
        in_scope 0
        tick
        {
                if --self.timer < 0
                        self.timer = 0

#ifset DEBUG
                if debug_flags & D_FUSES
                {
                        print "[Running fuse "; number self; ":  timer = ";
                        print number self.timer; "]"
                }
#endif

                if self.timer = 0
                        Deactivate(self)
                return self.timer
        }
}

class daemon
{
        type daemon
        size 0
        in_scope 0
}

routine Activate(a, set)                ! <set> is for fuses only
{
        local err

        a.in_scope = player
        a is active
        if a.type = fuse
        {
                if set
                        a.timer = set

                run a.activate_event
        }
        elseif a.type = daemon
        {
                if set and not a.#timer
                {
                        print "[WARNING:  Attempt to set nonexistent timer
                                property on daemon (object "; number a; ")]"
                        err = true
                }
                else
                        a.timer = set

                run a.activate_event
        }
        else
        {
                print "[WARNING:  Attempt to activate non-fuse/\
                daemon (object "; number a; ")]"
                err = true
        }

#ifset DEBUG
        if debug_flags & D_FUSES and not err
        {
                print "[Activating "; a.name; " "; number a;
                if a.type = fuse
                        print " (timer = "; number a.timer; ")";
                print "]"
        }
#endif

}

routine Deactivate(a)
{
        local err

        remove a
        a.in_scope = 0
        a is not active

        if a.type ~= fuse and a.type ~= daemon
        {
                print "[WARNING:  Attempt to deactivate non-fuse/\
                        daemon (object "; number a; ")]"
                err = true
        }
        else
        {
                run a.deactivate_event
        }

#ifset DEBUG
        if debug_flags & D_FUSES and not err
        {
                print "[Deactivating "; a.name; " "; number a; "]"
        }
#endif

}

#endif  ! ifclear NO_FUSES


!\
*****************************************************************************

CHARACTER SCRIPT ROUTINES

*****************************************************************************
\!

#ifclear NO_SCRIPTS

!----------------------------------------------------------------------------
! Script(character, number of steps)
! initializes space for the script, and returns its location in the
! setscript array; returns -1 if MAX_SCRIPTS is exceeded
!
! SYNTAX:  setscript[script(char, steps)] =  &CharRoutine1, object1,
!                                            &CharRoutine2, object2,
!                                            ...
!                                            (maximum of 32 steps)

routine Script(obj, steps)
{
        local o

        o = 0
        while scriptdata[o * 3] ~= obj and scriptdata[o * 3] ~= 0 and
                o < MAX_SCRIPTS
        {
                o++
        }
        if o = MAX_SCRIPTS
                return -1
        if scriptdata[o * 3] = 0
        {
                scriptdata[o * 3] = obj                ! the object
                number_scripts++
        }
        scriptdata[o * 3 + 1] = 0                       ! starting step
        scriptdata[o * 3 + 2] = steps                   ! total no. of steps
        return o * MAX_SCRIPTS * 2
}

routine FindScript(obj)
{
        local o

        o = 0
        while scriptdata[o * 3] ~= obj and o < MAX_SCRIPTS:  o++
        return o
}

#endif  ! ifclear NO_SCRIPTS

!----------------------------------------------------------------------------
! RunScripts
! runs all active character scripts via:  CharRoutine(character, object)

routine RunScripts
{

#ifclear NO_SCRIPTS

        local a, obj, step, total, routine, b
        local tempactor, tempverb, tempobject

        for (; a<number_scripts; a++)
        {
                obj = scriptdata[a * 3]         ! this object/character
                step = scriptdata[a * 3 + 1]    ! current step
                total = scriptdata[a * 3 + 2]   ! total steps in script

                if obj and total < 0            ! if skipping this script
                        scriptdata[a * 3 + 2] = scriptdata[a * 3 + 2] + 32767

                elseif obj and step < total and step >= 0
                {
                        ! action
                        routine = setscript[a * MAX_SCRIPT_STEPS + step * 2]

                        ! object being acted upon
                        b = setscript[a * MAX_SCRIPT_STEPS + step * 2 + 1]

#ifset DEBUG
                        if debug_flags & D_SCRIPTS
                        {
                                print "[Script for obj. ";
                                print number obj; " ("; obj.name; "), step ";
                                print number (step + 1); ":  $"; \
                                hex routine; ", obj. ";
                                print number b; " ("; b.name; ")]"
                        }
#endif

                        scriptdata[a * 3 + 1] = step + 1
                        tempactor = actor
                        tempverb = verbroutine
                        tempobject = object
                        actor = obj
                        verbroutine = routine
                        object = b
                        if not parent(actor).before
                        {
                                if not actor.before
                                {
                                        if not object.before
                                        {
                                                call routine(obj, b)
                                                run actor.after
                                        }
                                }
                        }
                        if actor in location:  actor is known
                        actor = tempactor
                        verbroutine = tempverb
                        object = tempobject
                }
                elseif step >= 0
                {
                        scriptdata[a * 3] = 0   ! clear this object's script
                        if a = number_scripts - 1
                                number_scripts--
                }
        }

#endif  ! ifclear NO_SCRIPTS

}

#ifclear NO_SCRIPTS

!----------------------------------------------------------------------------
! CancelScript(char)
! immediately halts execution of the script for <char>
!
! PauseScript(char)
! suspends execution of the script for <char>
!
! ResumeScript(char)
! resumes execution of a paused script
!
! SkipScript(char)
! skips <char>'s script only for the next call to RunScripts

routine CancelScript(obj)
{
        local o

        o = FindScript(obj)
        if o = MAX_SCRIPTS
                return
        scriptdata[o * 3] = 0
        if o = number_scripts - 1
                number_scripts--

#ifset DEBUG
                if debug_flags & D_SCRIPTS
                {
                        print "[Script for obj. ";
                        print number obj; " ("; obj.name; ") ";
                        print "cancelled]"
                }
#endif

        return true
}

routine PauseScript(obj)
{
        local o

        o = FindScript(obj)
        if o = MAX_SCRIPTS
                return
        if scriptdata[o * 3 + 1] >= 0           ! current step
        {
                scriptdata[o * 3 + 1] = scriptdata[o * 3 + 1] - 32767

#ifset DEBUG
                if debug_flags & D_SCRIPTS
                {
                        print "[Script for obj. ";
                        print number obj; " ("; obj.name; ") ";
                        print "paused]"
                }
#endif

                return true
        }
}

routine ResumeScript(obj)
{
        local o

        o = FindScript(obj)
        if o = MAX_SCRIPTS
                return
        if scriptdata[o * 3 + 1] < 0            ! current step
        {
                scriptdata[o * 3 + 1] = scriptdata[o * 3 + 1] + 32767

#ifset DEBUG
                if debug_flags & D_SCRIPTS
                {
                        print "[Script for obj. ";
                        print number obj; " ("; obj.name; ") ";
                        print "resumed]"
                }
#endif

                return true
        }
}

routine SkipScript(obj)
{
        local o

        o = FindScript(obj)
        if o = MAX_SCRIPTS
                return
        if scriptdata[o * 3 + 2] >= 0           ! total number of steps
        {
                scriptdata[o * 3 + 2] = scriptdata[o * 3 + 2] - 32767

#ifset DEBUG
                if debug_flags & D_SCRIPTS
                {
                        print "[Skipping script for obj. ";
                        print number obj; " ("; obj.name; ")]"
                }
#endif

                return true
        }
}


!----------------------------------------------------------------------------
! BASIC CHARACTER VERB ROUTINES:
!----------------------------------------------------------------------------
! LoopScript
! may be used in a script to repeatedly return to the starting step; the
! usage is:  &LoopScript, 0

routine LoopScript(obj)
{
        local o

        while scriptdata[o * 3] ~= obj and o < MAX_SCRIPTS:  o++
        if o = MAX_SCRIPTS
                return
        scriptdata[o * 3 + 1] = 0

#ifset DEBUG
        if debug_flags & D_SCRIPTS
        {
                print "[Looping script for obj. ";
                print number obj; " ("; obj.name; ")]"
        }
#endif

}

!----------------------------------------------------------------------------
! CharWait
! Script usage: &CharWait, 0

routine CharWait(char)
{

#ifset DEBUG
        if debug_flags & D_SCRIPTS
        {
                print "["; CThe(char); IsorAre(char, true); " waiting in:  ";
                print capital parent(char).name; ".]"
        }
#endif

        return true
}

!----------------------------------------------------------------------------
! CharMove
! Script usage:  &CharMove, <direction object>

routine CharMove(char, dir)
{
#ifclear NO_OBJLIB

        local newroom

        general = 1                     ! for signalling a character move
                                        ! to, for example, door.door_to

        newroom = parent(char).(dir.dir_to)

        if char in location and general = 1     ! door.door_to sets general
                                                ! to 2 if it prints a message
        {
                Message(&CharMove, 1, char, dir)
                event_flag = true
        }
        elseif char in location
                event_flag = true

        move char to newroom

#ifset DEBUG
        if debug_flags & D_SCRIPTS
        {
                print "["; CThe(char); IsorAre(char, true); " now in:  ";
                print capital parent(char).name; ".]"
        }
#endif

        if char in location and general = 1
        {
                Message(&CharMove, 2, char, dir)
                event_flag = true
        }
        elseif char in location
                event_flag = true

        general = 0                     ! always reset it

#endif  ! ifclear NO_OBJLIB

        run parent(char).after

        return true
}

!----------------------------------------------------------------------------
! CharGet
! Script usage:  &CharGet, <object>

routine CharGet(char, obj)
{
        if FindObject(obj, parent(char)) = 1
        {
                if Acquire(char, obj)
                {
                        if char in location
                        {
                                Message(&CharGet, 1, char, obj)
                                event_flag = true
                        }
                }
                return true
        }
}

!----------------------------------------------------------------------------
! CharDrop
! Script usage:  &CharDrop, <object>

routine CharDrop(char, obj)
{
        move obj to parent(char)
        char.holding = char.holding - obj.size
        if char in location
        {
                Message(&CharDrop, 1, char, obj)
                event_flag = true
        }
        return true
}

#endif  ! ifclear NO_SCRIPTS


!\
*****************************************************************************

LIBRARY MESSAGES

Most of the text printed by the library is generated by the Message routine.
To replace all of the default responses, replace the Message routine.  To
replace one or more responses, replace the NewMessages routine, and return
true for any replacement message that is provided; if NewMessages returns a
false value, Message prints the default response.

NOTE:  Other routines in HUGOLIB.H that print text independent of the
Message routine are:  PrintEndGame, PrintScore, ParseError, PrintStatusLine,
HoursMinutes, The, CThe, Art, CArt, IsorAre, MatchSubject, NumberWord,
DigitWord, DarkWarning, ObjectIs, and various debugging messages.

*****************************************************************************
\!

!----------------------------------------------------------------------------
! Message(&routine, number)
! prints message <number> for <routine>
!
! Message (&routine, number, var1, var2)
! where one or two variables--which may be objects or any other value--
! are used by message <number> for <routine>

routine Message(r, num, a, b)
{
        ! Check first to see if the NewMessages routine provides a
        ! replacement message:
        if NewMessages(r, num, a, b):  return

        select r

        case &EndGame
        {
                select num
                case 1
                {
                        print "\nThe game has ended.  Do you want to (R)ESTART,
                                R(E)STORE a saved game, ";
#ifclear NO_UNDO
                        if not UNDO_OFF         ! if not otherwise overridden
                                print "(U)NDO your last turn, ";
#endif
                        print "or (Q)UIT? ";
                }
                case 2
                {
                        print "Enter (R)ESTART, R(E)STORE, ";
#ifclear NO_UNDO
                        if not UNDO_OFF
                                print "(U)NDO, ";
#endif
                        print "or (Q)UIT: ";
                }
        }

        case &Parse
        {
                select num
                case 1:  print CThe(player); \
                                MatchPlural(player, "doesn't", "don't"); \
                                " need to refer to that."
                case 2:  print "(assuming you mean";
                case 3:  print ", respectively";
        }

        case &Speakto
        {
                if a = 0:  a = object   ! Speakto messages are sometimes
                                        ! co-opted by verb routines
                select num
                case 1:  print CThe(player); " probably ought not to waste
                                time talking to "; player.pronoun #4; "."
                case 2:  print CThe(a); IsorAre(a, true); " listening."
                case 3:  print CThe(a); " nod"; MatchSubject(a); \
                                " hello to "; The(player, true); "."
                case 4:  print CThe(a); " ignore"; MatchSubject(a); " "; \
                                The(player, true); "."
        }

        case &DescribePlace
        {
                select num
                case 1:  print "It's too dark to see anything."
                case 2:  print "There"; IsorAre(a, true); " "; Art(a); \
                                " here."
        }

        case &WhatsIn
        {
                select num
                case 1
                {
                        print CThe(player); IsorAre(player, true); " ";
                        if list_count < a
                                print "also ";
                        print "carrying";
                }
                case 2
                {
                        if FORMAT & USECHARNAMES_F
                                CThe(a)
                        else
                                print capital a.pronoun;
                        if list_count < b
                                print " also";
                        print MatchPlural(a, "has", "have");
                }
                case 3
                {
                        print "Also ";
                        if a.prep
                                print a.prep; " ";
                        elseif a is platform
                                print "sitting on ";
                        else
                                print "inside ";
                }
                case 4
                {
                        if a.prep
                                print capital a.prep; " ";
                        elseif a is platform
                                print "Sitting on ";
                        else
                                print "Inside ";
                }
        }

        case &CheckReach
        {
                select num
                case 1
                {
                        print "Except that "; The(parent(a)); \
                                MatchPlural(parent(a), "has", "have"); \
                                " "; The(a); "."
                }
                case 2
                {
                        print "Except that "; The(parent(a)); \
                                MatchPlural(parent(a), "doesn't", "don't"); \
                                " want to give "; The(player, true); \
                                " "; The(a); "."
                }
                case 3:  print CThe(player); " can't reach "; The(a); \
                                " from "; The(parent(player)); "."
        }

        case &YesorNo
        {
                select num
                case 1
                        print "Please answer YES or NO: ";
                case 2
                        print "YES or NO: ";
        }

#ifclear NO_MENUS
        case &Menu
        {
                print "[N]ext item"; to (display.linelength - 11); \
                        "[Q]uit menu"
                print "[P]revious item"; to (display.linelength - 17);
                print "[Enter] to select"
        }
#endif

#ifclear NO_SCRIPTS
#ifclear NO_OBJLIB
        case &CharMove
        {
                select num
                case 1
                {
                        print "\n"; CThe(a); " head"; MatchSubject(a); " ";
                        if b = u_obj or b = d_obj
                                print b.name; "ward."
                        else
                        {
                                print "off to the ";
                                print b.name; "."
                        }
                }
                case 2
                {
                        print "\n"; CThe(a); " arrive"; MatchSubject(a); \
                                " from ";
                        if b ~= u_obj and b ~= d_obj
                                print "the "; (b.dir_from).name; "."
                        elseif b = u_obj
                                print "below."
                        else
                                print "above."
                }
        }
#endif  ! ifclear NO_OBJLIB

        case &CharGet:  print "\n"; CThe(a); " pick"; MatchSubject(a); \
                        " up "; The(b); "."

        case &CharDrop:  print "\n"; CThe(a); " put"; MatchSubject(a); \
                        " down "; The(b); "."
#endif  ! ifclear NO_SCRIPTS
}

routine NewMessages(r, num, a, b)       ! The NewMessages routine may be
{                                       ! replaced, and should return true
        return false                    ! if a replacement message <num>
}                                       ! exists for routine <r>


#set _COMPILING_HUGOLIB

!----------------------------------------------------------------------------
! Include verb library

#include "verblib.h"

!----------------------------------------------------------------------------
! Include verb stub routines if specified

#ifset VERBSTUBS
#include "verbstub.h"
#endif

!----------------------------------------------------------------------------
! Include object library unless otherwise specified

#ifclear NO_OBJLIB
#include "objlib.h"
#endif

!----------------------------------------------------------------------------
! Include debugging routines if specified

#ifset DEBUG
#include "hugofix.h"
#endif

#ifset DEBUG
object last_library_object
{}
#endif

#clear _COMPILING_HUGOLIB

!----------------------------------------------------------------------------
! NOTE:  In addition to the flags VERBSTUBS and DEBUG which are used to
! include additional library files, a number of compiler flags can be set
! to exclude portions of HUGOLIB.H.  These are:  NO_AUX_MATH, NO_FONTS,
! NO_FUSES, NO_MENUS, NO_OBJLIB, NO_RECORDING, NO_SCRIPTS, NO_STRING_ARRAYS,
! NO_VERBS, and NO_XVERBS.
!----------------------------------------------------------------------------

#endif  ! _HUGOLIB_H
