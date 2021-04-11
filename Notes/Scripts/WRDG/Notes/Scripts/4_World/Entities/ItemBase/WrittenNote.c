class WrittenNote extends Paper
{
	void SetWrittenNoteData(WrittenNoteData data)
	{
		m_NoteContents = data;
	}

    override void SetActions()
	{
		super.SetActions();

		AddAction(ActionReadPaper);
		AddAction(ActionReadPaperTarget);
	}
}