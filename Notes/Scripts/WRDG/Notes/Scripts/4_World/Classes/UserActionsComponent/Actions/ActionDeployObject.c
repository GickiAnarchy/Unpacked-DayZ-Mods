modded class ActionDeployObject
{
    protected PluginNotesLog m_NotesLog;

    void ActionDeployObject()
    {
        if (GetGame() && GetGame().IsServer())
		{
			m_NotesLog = PluginNotesLog.Cast(GetPlugin(PluginNotesLog));
		}
    }

    override void SetupAnimation(ItemBase item)
    {
        if (item.IsKindOf("Paper") || item.IsInherited(WrittenNote))
        {
            m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
            return;
        }

        super.SetupAnimation(item);
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (!GetGame().IsMultiplayer() || GetGame().IsClient())
        {
            if (player.IsPlacingLocal() && (item.IsKindOf("Paper") || item.IsInherited(WrittenNote)))
                return true;
        }

        return super.ActionCondition(player, target, item);
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        WrittenNote note;
        PlayerIdentity identity = action_data.m_Player.GetIdentity();

        if (m_NotesLog && identity && WrittenNote.CastTo(note, action_data.m_MainItem))
        {
            string pos = note.GetPosition().ToString();
            string message = note.GetWrittenNoteData().GetNoteText();

            m_NotesLog.OnPlaceNote(identity, pos, message);
        }

        super.OnFinishProgressServer(action_data);
    }
}