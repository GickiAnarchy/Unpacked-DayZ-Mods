class PluginNotesLog extends PluginBase
{
    protected FileHandle m_LogFile;

    protected const string m_LogDirectory = "$profile:Notes/";

    void PluginNotesLog()
    {
        if (!FileExist(m_LogDirectory) && GetGame().IsMultiplayer())
        {
            PrintFormat("[Notes]::MakeDirectory - %1", m_LogDirectory);
			MakeDirectory(m_LogDirectory);
		}
    }

    void PrintLog(string message)
    {
        m_LogFile = OpenFile(CurrentLogFile(), FileMode.APPEND);
        message = string.Format("[%1-%2] %3\n", GetDate(), GetTime(), message);
        FPrintln(m_LogFile, message);
        CloseFile(m_LogFile);
    }

    void OnPlaceNote(PlayerIdentity identity, string position, string message)
    {
        if (!GetGame().IsMultiplayer())
            return;

        string log = string.Format("%\"%1\"(id=%2) placed a note at %3\n%4", identity.GetName(), identity.GetPlainId(), position, GetNoteFormatted(message));
        PrintLog(log);
    }

    void OnWriteNote(PlayerIdentity identity, string message)
    {
        if (!GetGame().IsMultiplayer())
            return;

        string log = string.Format("\"%1\"(id=%2) wrote a note\n%3", identity.GetName(), identity.GetPlainId(), GetNoteFormatted(message));
        PrintLog(log);
    }

    protected string GetNoteFormatted(string message)
    {
        string header = "========== START NOTE ===========";
        string footer = "=========== END NOTE ============";
        return string.Format("%1\n%2\n%3", header, message, footer);
    }

    protected string GetTime()
    {
        int hour, minute, second;
        GetHourMinuteSecond(hour, minute, second);
        return string.Format("%1:%2:%3", hour.ToStringLen(2), minute.ToStringLen(2), second.ToStringLen(2));
    }

    protected string GetDate()
    {
        int year, month, day;
        GetYearMonthDay(year, month, day);
        return string.Format("%1.%2.%3", year.ToStringLen(2), month.ToStringLen(2), day.ToStringLen(2));
    }

    protected string CurrentLogFile()
    {
        return string.Format("%1Notes_%2.log", m_LogDirectory, GetDate());
    }
}