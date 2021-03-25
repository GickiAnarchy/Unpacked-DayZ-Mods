static ref TZLogger g_TZLogger;
static ref TZLogger GetTZLogger(){
	if (!g_TZLogger) {
		g_TZLogger = new ref TZLogger();
	}
	return g_TZLogger;
}

static ref TZManager m_TZManager;
static ref TZManager GetTZManager() {
	if ( !m_TZManager ) {
		m_TZManager = new ref TZManager;
	}
	return m_TZManager;
}

static ref ToxicAreaSettings GetTZConfig()	{
	return GetTZManager().m_ActiveToxicAreaSettings;
}

static ref LootTZSettings GetTZLootConfig()  {
	return GetTZManager().m_ActiveLootSettings;
}


static string GetDateTimeStamp() {
		int year, month, day, hour, minute, second;
		string y, m, d, h, n, s, timeStamp;
		GetHourMinuteSecondUTC(hour, minute, second);
		GetYearMonthDayUTC(year, month, day);
		y = year.ToString().Trim();
		m = month.ToString().Trim();
		d = day.ToString().Trim();
		h = hour.ToString().Trim();
		n = minute.ToString().Trim();
		s = second.ToString().Trim();
		if (m.Length() == 1) { m = "0" + m; }
		if (d.Length() == 1) { d = "0" + d; }
		if (h.Length() == 1) { h = "0" + h; }
		if (n.Length() == 1) { n = "0" + n; }
		if (s.Length() == 1) { s = "0" + s; }
		timeStamp = string.Format("%1%2%3%4%5%6", y, m, d, h, n, s);
		return timeStamp;
	}