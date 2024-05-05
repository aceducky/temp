if status is-interactive

    # Commands to run in interactive sessions can go here
    set -U fish_greeting Welcome $USER (date +%T)


    ## aliases
    alias edit_fishrc="nvim ~/.config/fish/config.fish"
    alias source_fishrc="source ~/.config/fish/config.fish"

    alias ..="cd .."
    alias ...="cd .. && cd .."


    # pnpm
    set -gx PNPM_HOME "/home/aceducky/.local/share/pnpm"
    if not string match -q -- $PNPM_HOME $PATH
        set -gx PATH "$PNPM_HOME" $PATH
    end
    # pnpm end
    zoxide init fish --cmd cd | source

    starship init fish | source

end
